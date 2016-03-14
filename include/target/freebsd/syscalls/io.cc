#ifndef SYSCALL_IO_H_
#define SYSCALL_IO_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>

/*
 * System calls defined in this file.
 */
namespace Syscall {

    #if SYSCALL_EXISTS(openat)
    SYSTEM_CALL int     openat(int, const char *, int);
    SYSTEM_CALL int     openat(int, const char *, int, mode_t);
    #endif
    SYSTEM_CALL int     open(const char *, int);
    SYSTEM_CALL int     open(const char *, int, mode_t);
    SYSTEM_CALL int     access(const char *, int);
    SYSTEM_CALL int     dup(int);
    SYSTEM_CALL int     dup2(int, int);
    SYSTEM_CALL off_t   lseek(int, off_t, int);
    SYSTEM_CALL ssize_t read(int, void *, size_t);
    SYSTEM_CALL ssize_t write(int, const void *, size_t);
    SYSTEM_CALL int     fsync(int);
    SYSTEM_CALL int     poll(struct pollfd *, nfds_t, int);
    SYSTEM_CALL int     select(int, fd_set *, fd_set *, fd_set *, struct timeval *);
    SYSTEM_CALL int     getdents(unsigned int, struct dirent *, unsigned int);
    SYSTEM_CALL ssize_t readlink(const char *, char *, size_t);
    SYSTEM_CALL int     fstat(int, struct stat *);
    SYSTEM_CALL int     stat(int, struct stat *);
    SYSTEM_CALL int     unlink(const char *);
    SYSTEM_CALL int     close(int);
    SYSTEM_CALL int     mkdir(const char *, mode_t);
    SYSTEM_CALL int     rmdir(const char *);
    SYSTEM_CALL int     getcwd(char *, size_t);
    SYSTEM_CALL int     chdir(const char *);
    SYSTEM_CALL int     fchdir(int fd);
    SYSTEM_CALL int     chroot(const char *);
    SYSTEM_CALL int     chown(const char *, uid_t, gid_t);
    SYSTEM_CALL int     fchown(int, uid_t, gid_t);
    SYSTEM_CALL int     chmod(const char *, mode_t);
    SYSTEM_CALL int     fchmod(int, mode_t);
    SYSTEM_CALL int     fcntl(int, int);
    SYSTEM_CALL int     fcntl(int, int, void *);
    SYSTEM_CALL int     ioctl(int, unsigned long);
    SYSTEM_CALL int     ioctl(int, unsigned long, void *);
    SYSTEM_CALL int     ioctl(int, unsigned long, long);

    #if SYSCALL_EXISTS(openat)
    SYSTEM_CALL
    int openat(int dirfd, const char *path, int flags)
    {
        return DO_SYSCALL(openat, dirfd, path, flags);
    }

    SYSTEM_CALL
    int openat(int dirfd, const char *path, int flags, mode_t mode)
    {
        return DO_SYSCALL(openat, dirfd, path, flags, mode);
    }
    #endif

    SYSTEM_CALL
    int open(const char *path, int flags)
    {
        return DO_SYSCALL(openat, AT_FDCWD, path, flags);
    }

    SYSTEM_CALL
    int open(const char *path, int flags, mode_t mode)
    {
        return DO_SYSCALL(open, path, flags, mode);
    }

    SYSTEM_CALL
    int access(const char *path, int mode)
    {
        return DO_SYSCALL(access, path, mode);
    }

    SYSTEM_CALL
    int dup(int oldfd)
    {
        return DO_SYSCALL(dup, oldfd);
    }

    SYSTEM_CALL
    int dup2(int filedes, int filedes2)
    {
        return DO_SYSCALL(dup2, filedes, filedes2);
    }

    SYSTEM_CALL
    off_t lseek(int fd, off_t offset, int whence)
    {
        return DO_SYSCALL(lseek, fd, offset, whence);
    }

    SYSTEM_CALL
    ssize_t read(int fd, void *buf, size_t count)
    {
        return DO_SYSCALL(read, fd, buf, count);
    }

    SYSTEM_CALL
    ssize_t write(int fd, const void *buf, size_t count)
    {
        return DO_SYSCALL(write, fd, buf, count);
    }

    SYSTEM_CALL
    int fsync(int fildes)
    {
        return DO_SYSCALL(fsync, fildes);
    }

    SYSTEM_CALL
    int poll(struct pollfd *fds, nfds_t nfds, int timeout)
    {
        return DO_SYSCALL(poll, fds, nfds, timeout);
    }

    SYSTEM_CALL
    int select(int nfds, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds, struct timeval *timeout)
    {
        return DO_SYSCALL(select, nfds, read_fds, write_fds, except_fds, timeout);
    }

    SYSTEM_CALL
    int getdents(unsigned int fd, struct dirent *dirp, unsigned int count)
    {
        return DO_SYSCALL(getdents, fd, dirp, count);
    }

    SYSTEM_CALL
    ssize_t readlink(const char *pathname, char *buf, size_t bufsiz)
    {
        return DO_SYSCALL(readlink, pathname, buf, bufsiz);
    }

    SYSTEM_CALL
    int fstat(int fd, struct stat *buf)
    {
        return DO_SYSCALL(fstat, fd, buf);
    }

    SYSTEM_CALL
    int stat(const char *path, struct stat *buf)
    {
        return DO_SYSCALL(stat, path, buf);
    }

    SYSTEM_CALL
    int unlink(const char *path)
    {
        return DO_SYSCALL(unlink, path);
    }

    SYSTEM_CALL
    int close(int fd)
    {
        return DO_SYSCALL(close, fd);
    }

    SYSTEM_CALL
    int mkdir(const char *path, mode_t mode)
    {
        return DO_SYSCALL(mkdir, path, mode);
    }

    SYSTEM_CALL
    int rmdir(const char *path)
    {
        return DO_SYSCALL(rmdir, path);
    }

    SYSTEM_CALL
    int getcwd(char *buf, size_t size)
    {
        return DO_SYSCALL(__getcwd, buf, size);
    }

    SYSTEM_CALL
    int chdir(const char *path)
    {
        return DO_SYSCALL(chdir, path);
    }

    SYSTEM_CALL
    int fchdir(int fd)
    {
        return DO_SYSCALL(fchdir, fd);
    }

    SYSTEM_CALL
    int chroot(const char *path)
    {
        return DO_SYSCALL(chroot, path);
    }

    SYSTEM_CALL
    int chown(const char *path, uid_t owner, gid_t group)
    {
        return DO_SYSCALL(chown, path, owner, group);
    }

    SYSTEM_CALL
    int fchown(int fd, uid_t owner, gid_t group)
    {
        return DO_SYSCALL(fchown, fd, owner, group);
    }

    SYSTEM_CALL
    int chmod(const char *path, mode_t mode)
    {
        return DO_SYSCALL(chmod, path, mode);
    }

    SYSTEM_CALL
    int fchmod(int fd, mode_t mode)
    {
        return DO_SYSCALL(fchmod, fd, mode);
    }

    SYSTEM_CALL
    int fcntl(int fd, int cmd)
    {
        return DO_SYSCALL(fcntl, fd, cmd);
    }

    /*
     * The best solution would be an 'auto' arg here.
     * But gcc has a bug and cannot generate the syscall correctly.
     * Keep it like this until gcc is fixed (probably never), or
     * until gcc support is definitely dropped in favor of clang.
     */
    SYSTEM_CALL
    int fcntl(int fd, int cmd, void *arg)
    {
        return DO_SYSCALL(fcntl, fd, cmd, arg);
    }

    SYSTEM_CALL
    int ioctl(int fd, unsigned long request)
    {
        return DO_SYSCALL(ioctl, fd, request);
    }

    /*
     * See above comment for fcntl.
     */
    SYSTEM_CALL
    int ioctl(int fd, unsigned long request, void *arg)
    {
        return DO_SYSCALL(ioctl, fd, request, arg);
    }

    SYSTEM_CALL
    int ioctl(int fd, unsigned long request, long arg)
    {
        return ioctl(fd, request, reinterpret_cast<void *>(arg));
    }
}

#endif
