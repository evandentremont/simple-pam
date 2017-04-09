#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <sys/sysinfo.h>

/* expected hook */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
	return PAM_SUCCESS;
}

/* expected hook, this is where custom stuff happens */
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {

	struct sysinfo s_info;
	int error = sysinfo(&s_info);
	if(error != 0){
		printf("code error = %d\n", error);
	}

	if ( s_info.uptime < 180) { 
		// If the system has been up for less than 180 seconds, allow access.
		return PAM_SUCCESS;
	}
	// Otherwise.. They haven't proved physical access by rebooting :)
	return PAM_AUTH_ERR;


}
