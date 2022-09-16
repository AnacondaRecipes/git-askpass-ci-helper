# git-askpass-ci-helper
Utility for outputting git credentials using GIT_ASKPASS

The GIT_ASKPASS mechanism requires an actual executable with no arguments.
This is easy to implement on unix with a shell script because `#!` is interpretted
by the kernel and thus we can easily write a script to output whatever our secrets.

Windows is a different story and a real executable must be called.
