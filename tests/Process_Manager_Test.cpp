// $Id$

// ============================================================================
//
// = LIBRARY
//    tests
//
// = FILENAME
//    Process_Manager_Test.cpp
//
// = DESCRIPTION
//      This program tests the various methods provided by
//      <ACE_Process_Manager>.  It illustrates both the explicit <wait>
//      functions and the Reactor-style auto-reaping.  There's an
//      Exit_Handler class that can print out (in Debug mode) when a
//      child has been reaped.
//
//      The child processes spawned are simply this program itself, with
//      an integer argument specifying how long to "process" (actually,
//      the child just sleeps for the specified length of time).
//
// = AUTHOR
//    Douglas C. Schmidt <schmidt@cs.wustl.edu> and
//    Dave Madden <dhm@mersenne.com>
//
// ============================================================================

#include "test_config.h"
#include "ace/Process_Manager.h"
#include "ace/Get_Opt.h"

ACE_RCSID(tests, Process_Manager_Test, "Process_Manager_Test.cpp,v 4.11 1999/09/02 04:36:30 schmidt Exp")

#if defined(__BORLANDC__) && __BORLANDC__ >= 0x0530
USELIB("..\ace\aced.lib");
//---------------------------------------------------------------------------
#endif /* defined(__BORLANDC__) && __BORLANDC__ >= 0x0530 */

#if !defined (ACE_LACKS_FORK) && defined (ACE_HAS_THREADS)

static bool debug_test = false;

class Exit_Handler : public ACE_Event_Handler 
{
public:
  Exit_Handler (const char *msg): msg_ (msg) { }

  virtual int handle_exit (ACE_Process *proc) 
  {
    if (debug_test)
      ACE_DEBUG ((LM_DEBUG,
                  ASYS_TEXT ("(%P|%t) Exit_Handler(%s) got %d: %d\n"),
                  msg_,
                  int (proc->getpid ()),
                  int (proc->exit_code ()) ));
    return 0;
  }
private:
  const char *msg_;
};

static void
usage (const char *argv0)
{
  ACE_ERROR ((LM_ERROR,
              ASYS_TEXT ("usage: %s [-d] [sleep-seconds]\n"),
              argv0));
  ACE_OS::exit (0);
}

static pid_t
spawn_child (const char *argv0,
             ACE_Process_Manager &mgr,
             int sleep_time = 0)
{
  ACE_Process_Options opts;

  opts.command_line ("%s %s %d",
                     argv0,
                     debug_test ? "-d" : "",
                     sleep_time);

  pid_t  result = mgr.spawn (opts);

  if (debug_test)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) spawned child: %d\n"),
                int (result)));
  return result;
}

int
main (int argc, ASYS_TCHAR *argv[])
{
  ACE_Get_Opt args (argc, argv, "d");

  for (int arg = args (); arg != EOF; arg = args ())
    switch (arg) 
      {
      case 'd':
        debug_test = true;
        break;
      default:
        usage (argv[0]);
        break;
      }

  if (args.optind == argc - 1) 
    {     // child process: sleep & exit
      int secs = atoi (argv[args.optind]);
      ACE_OS::sleep (secs ? secs : 1);
      if (debug_test) 
        ACE_DEBUG ((LM_DEBUG,
                    ASYS_TEXT ("(%P|%t) about to exit with code %d\n"),
                    secs));
      ACE_OS::exit (secs);
    }

  if (args.optind != argc)      // incorrect usage
    usage (argv[0]);

  // Try the explicit <ACE_Process_Manager::wait> functions

  ACE_Process_Manager mgr;

  mgr.register_handler (new Exit_Handler ("default"));
  
  ACE_exitcode exitcode;

  // wait for a specific PID
  pid_t child1 = spawn_child (argv[0],
                              mgr,
                              1);
  pid_t result1 = mgr.wait (child1,
                            &exitcode);

  if (debug_test)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) waited for child %d: %d\n"),
                child1,
                exitcode));

  // wait for a specific PID; another should finish first
  pid_t child2 = spawn_child (argv[0],
                              mgr,
                              1);
  pid_t child3 = spawn_child (argv[0],
                              mgr,
                              4);
  pid_t result2 = mgr.wait (child3,
                            &exitcode);

  if (debug_test)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) waited for child %d: %d\n"),
                child3,
                exitcode));

  // Now wait for any...should get the one that finished earlier.

  pid_t result3 = mgr.wait (0,
                            &exitcode);

  if (debug_test)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) waited for any child: %d\n"),
                exitcode));

  // Try the timed wait functions

  // This one shouldn't timeout:
  pid_t child4 = spawn_child (argv[0],
                              mgr,
                              1);
  pid_t result4 = mgr.wait (0,
                            ACE_Time_Value (4),
                            &exitcode);

  if (debug_test)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) waited for any child: %d\n"),
                exitcode));

  // This one should timeout:
  pid_t child5 = spawn_child (argv[0],
                              mgr,
                              4);
  pid_t result5 = mgr.wait (0,
                            ACE_Time_Value (1),
                            &exitcode);
  if (debug_test) 
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) waited for any child: %d\n"),
                exitcode));

  // Now wait indefinitely to clean up...
  result5 = mgr.wait (0,
                      &exitcode);

  if (debug_test)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) waited for child 5 again: %d\n"),
                exitcode));

  // Finally, try the reactor stuff...
  mgr.open (ACE_Process_Manager::DEFAULT_SIZE,
            ACE_Reactor::instance ());

  pid_t child6 = spawn_child (argv[0],
                              mgr,
                              5);
  pid_t child7 = spawn_child (argv[0],
                              mgr,
                              6);

  mgr.register_handler (new Exit_Handler ("specific"),
                        child6);

  ACE_Time_Value how_long (10);

  ACE_Reactor::instance ()->run_event_loop (how_long);

  if (debug_test)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("(%P|%t) done!\n") ));

  return 0;
}

#else
int 
main (int, ASYS_TCHAR *[])
{
  ACE_START_TEST (ASYS_TEXT ("Process_Manager_Test"));
  ACE_ERROR ((LM_ERROR,
              ASYS_TEXT ("The ACE Process Manager is not supported on this platform\n")));
  ACE_END_TEST;
  return 0;
}
#endif /* !ACE_LACKS_FORK && ACE_HAS_THREADS */
