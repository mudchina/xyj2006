#ifndef __LOGIN__
#define __LOGIN__

#define LOGIN_TIMEOUT           180

#define XYJ_SITES 			"/adm/etc/xyj_sites"
#define BANNER 				"/adm/etc/banner"
#define WELCOME				"/adm/etc/welcome"
#define NEW_PLAYER_INFO		"/adm/etc/new_player"
#define MOTD				"/adm/etc/motd"

#define WIZLIST				"/adm/etc/wizlist"
#define BANNED_ID			"/adm/etc/banned_id"

#define START_ROOM			"/d/city/kezhan"
#define DEATH_ROOM			"/d/death/gate"
#define REVIVE_ROOM			"/d/ourhome/kedian"

// This is how much users can 'enter' the mud actually. Maintained
// by LOGIN_D. The max number of connections can be built between
// server(MudOS) and users' client(telnet) is specified in MudOS
// config file, which must be larger than MAX_USER to allow users
// including wizards and admins have chance to connect.
// By Annihilator (02-22-95)
#define MAX_USERS			350

// This defines the robot checker room. All susspecious robot player
// will be transfered to this room. You should give a chance for those
// non-robot player to return to the world.
// By Annihilator (05-26-95)
#define ROBOT_CHECK			"/d/wiz/courthouse"

// This defines the minimum wiz_level of users that are allowed to 
// enter the mud. Note players has wiz_level 0.
#define WIZ_LOCK_LEVEL 0

// define the following to limit the number of players allowed to login
// from a single site.
#define MAX_LOGIN 100
// this defines what is one login site when deciding
// multi-login. can either be 0 or 1.
// 0: use the first 3 fields of numerical IP as a site.
// 1: use the full 4 fileds of numerical IP as a site.
#define LOGIN_SITE   0

#endif

