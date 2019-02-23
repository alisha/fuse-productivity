/**
* A productivity tool designed to help people reduce their screen time
* Makes all your files on your computer inaccessible (except from the command line)
*/

// You need to define your FUSE version before you include fuse.h!
#define FUSE_USE_VERSION 31

#include <fuse.h>
#include <errno.h>

// Set up our new FUSE program
static void *work_init(struct fuse_conn_info* conn, struct fuse_config* cfg) {
	(void) conn;
	// Disable kernel caching because file contents won't be modified,
	// and we don't want to have variable syscall behavior
	cfg->kernel_cache = 1;
	return NULL;
}

// We don't want the user to be able to open any files
static int work_open(const char* path, struct fuse_file_info* fi) {
	(void) path;
	(void) fi;
	return -ENOENT;
}

static struct fuse_operations oper = {
	.init = work_init,
	.open = work_open,
};

int main(int argc, char* argv[]) {
	umask(0);
	return fuse_main(argc, argv, &oper, NULL);
}
