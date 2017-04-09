Intro
=====

This is a PAM module that checks system uptime. It can be useful for ensuring a user has physical access to a device. By default; that it's been power cycled within the last 3 minutes.

To build for Ubuntu, you should be able to use `./buildPam.sh`. Other distros may require some slight customization. 

Since it's a shared library, PAM can use it on the fly without having to restart.

**Build Test**

`g++ -o pam_test src/test.c -lpam -lpam_misc`

Simple Usage
------------

The build scripts will take care of putting your module where it needs to be, `/lib/x86_64-linux-gnu/security`, so the next thing to do is edit config files.

The config files are located in `/etc/pam.d/` and the one I edited was `/etc/pam.d/common-auth`.

The test application tests auth and account functionality (although account isn't very interesting). At the top of the `/etc/pam.d/common-auth` put the following line:

	auth requisite mypam.so


To run the test program, just do: `./pam_test {username}` and, depending on uptime, it will fail immediately or pass through to the password / other prompts.

Resources
=========

These guides give brief overviews about PAM and how to write modules.  This is useful if you already have a little knowledge.

* [Writing PAM Modules, Part One](http://linuxdevcenter.com/pub/a/linux/2002/05/02/pam_modules.html)
* [Writing PAM Modules, Part Two](http://linuxdevcenter.com/pub/a/linux/2002/05/23/pam_modules.html)
* [Writing PAM Modules, Part Three](http://linuxdevcenter.com/pub/a/linux/2002/05/30/pam_modules.html)

Others
------

Good example for simple authentication.  I adapted this one in my simple PAM module.

[2-factor authentication & writing PAM modules](http://ben.akrin.com/?p=1068)

Gives an example program that uses PAM. I adapted this for testing my PAM module.

[Example PAM application](http://www.kernel.org/pub/linux/libs/pam/Linux-PAM-html/adg-example.html)
