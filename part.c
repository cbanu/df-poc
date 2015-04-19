#include <stdio.h>
#include <string.h>
#include <mntent.h>
int main() {
	printf("part\n");
	FILE* f = setmntent("/proc/mounts", "r");
	struct mntent *me;
	while (NULL != (me = getmntent(f))) {
		if ((0 == strcmp(me->mnt_type, "tmpfs")) ||
			(0 == strcmp(me->mnt_type, "ext4i"))) {
		}
		printf("fsname=%s dir=%s type=%s\n", me->mnt_fsname, me->mnt_dir, me->mnt_type);
	}
	endmntent(f);
	f = NULL;
	return 0;
}
