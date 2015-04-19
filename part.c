#include <stdio.h>
#include <string.h>
#include <mntent.h>
#include <sys/statvfs.h>

int main() {
	printf("'df' PoC\n");
	FILE* f = setmntent("/proc/mounts", "r");
	struct statvfs svfs;
	struct mntent *me;
	while (NULL != (me = getmntent(f))) {
		if ((0 == strcmp(me->mnt_type, "tmpfs")) ||
			(0 == strcmp(me->mnt_type, "ext4"))) {
			printf("fsname=%s dir=%s type=%s\n", me->mnt_fsname, me->mnt_dir, me->mnt_type);
			memset(&svfs, 0, sizeof(svfs));
			if (0 == statvfs(me->mnt_dir, &svfs)) {
				printf("bsize %lu\n", svfs.f_bsize);
				printf("blocks %lu\n", svfs.f_blocks);
				printf("bfree %lu\n", svfs.f_bfree);
				printf("bavail %lu\n", svfs.f_bavail);
			}
		}
	}
	endmntent(f);
	f = NULL;
	return 0;
}
