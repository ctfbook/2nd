#include <sys/ptrace.h>

int is_debugged()
{
  if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
    return 1; // ptraceが失敗したのでデバッガが使われている
  } else {
    return 0;
  }
}
