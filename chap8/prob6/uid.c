#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main()
{
	printf("my realistic user id: %d(%s) \n", getuid(), getpwuid(getuid()) -> pw_name);
	printf("my Valid USER id: %d(%s) \n", geteuid(), getpwuid(geteuid()) -> pw_name);
	printf("my realistic group id: %d(%s) \n", getgid(), getgrgid(getgid()) -> gr_name);
	printf("my valid group id: %d(%s) \n", getegid(), getgrgid(getegid()) -> gr_name);
}
