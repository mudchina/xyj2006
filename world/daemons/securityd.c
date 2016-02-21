// securityd.c

#include <login.h>

private mapping wiz_status;
private mapping wiz_sites;

private string *wiz_levels = ({
   "(player)",
   "(elder)",
   "(immortal)",
   "(apprentice)",
   "(wizard)",
   "(arch)",
   "(admin)"
});


private mapping trusted_read = ([/*可以读*/
     "/":        ({ "(arch)","(admin)","(immortal)","(apprentice)","(wizard)",}),
     "p":        ({ "(player)",}),
]);
private mapping trusted_write = ([/*可以写*/
      "/":            ({ "(admin)","(arch)",}),
     "cmds/std":      ({ "(arch)" }),
     "cmds/usr":      ({ "(arch)" }),
     "daemon":        ({ "(arch)",}),
     "doc":           ({ "(arch)","(wizard)",}),
]);

private mapping exclude_write = ([/*不能写*/
    "adm":      ({ "(wizard)","(apprentice)","(immortal)", }),
    "include":  ({ "(wizard)","(apprentice)","(immortal)", }),
    "data":     ({ "(wizard)","(apprentice)","(immortal)",}),
    "log":      ({ "(wizard)","(apprentice)","(immortal)", }),
    "cmds":     ({ "(wizard)","(apprentice)","(immortal)",}),
    "feature":  ({ "(wizard)","(apprentice)","(immortal)",}),
    "std":      ({ "(wizard)","(apprentice)","(immortal)",}),
    "d" :       ({ "(apprentice)","(immortal)",}),
    "u":        ({ "(wizard)","(apprentice)","(immortal)",}),
    "topten":   ({ "(wizard)","(apprentice)","(immortal)",}),
    "binaries": ({ "(wizard)","(apprentice)","(immortal)",}),
    "p":        ({ "(wizard)","(apprentice)","(immortal)",}),
]);

private mapping exclude_read = ([/*不能读*/
    "adm":      ({ "(wizard)","(apprentice)","(immortal)",}),
    "data":     ({ "(wizard)","(apprentice)","(immortal)",}),
    "cmds": ({ "(wizard)","(apprentice)","(immortal)",}),
    "d/dntg":   ({ "(apprentice)","(immortal)",}),
    "u":        ({ "(wizard)","(apprentice)","(immortal)",}),
    "include":  ({ "(apprentice)","(immortal)",}),
    "std":      ({ "(apprentice)","(immortal)",}),
    "daemon":   ({ "(apprentice)","(immortal)",}),
    "log"    :  ({ "(wizard)","(apprentice)","(immortal)",}),
    "feature":  ({ "(apprentice)","(immortal)",}),
    "d":        ({ "(immortal)", }),
    "topten":   ({ "(apprentice)","(immortal)",}),
    "binaries": ({ "(wizard)","(apprentice)","(immortal)",}),
    "p":        ({ "(apprentice)","(immortal)",}),
]); 

void create()
{
   string *wizlist, wiz_name, wiz_level, wiz_site;
   int i;

   wizlist = explode(read_file(WIZLIST), "\n");
   wiz_status = allocate_mapping(sizeof(wizlist));
   wiz_sites = allocate_mapping(sizeof(wizlist));
   for(i=0; i<sizeof(wizlist); i++) {
     if( wizlist[i][0]=='#' )   continue;
     if( sscanf(wizlist[i], "%s %s %s", wiz_name, wiz_level,
        wiz_site) == 3 )  {
         wiz_status[wiz_name] = wiz_level;
         wiz_sites[wiz_name] = wiz_site;
     }
     else if( sscanf(wizlist[i], "%s %s", wiz_name, wiz_level)!=2 ) continue;
     else
     {
        wiz_status[wiz_name] = wiz_level;
        wiz_sites[wiz_name] = "";
     }
   }
}


string *query_wizlist() { return keys(wiz_status); }

// This function returns the status of an uid.
string get_status(mixed ob)
{
   string euid;
   if( objectp(ob) ) {
     euid = geteuid(ob);
     if( !euid ) euid = getuid(ob);
   }
   else if( stringp(ob) ) euid = ob;
   if (!mapp(wiz_status)) return "(player)";
   if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
   else if( member_array(euid, wiz_levels)!=-1 ) return euid;
   else return "(player)";
}

int match_wiz_site(object ob, string site)
{
    string* line;
   string euid;

   euid = ob->query("id");

   if( undefinedp(wiz_sites[euid]) || wiz_sites[euid] == "" )  return 1;

   line = ({});
   line += ({site});
if(sizeof(regexp(line, wiz_sites[euid])) == 1 )
     return 1;

   return 0;
}


int get_wiz_level(object ob)
{
   return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
   string uid, *wiz, wizlist;
   int i;
   object temp;
   if( geteuid(previous_object())!= ROOT_UID ) return 0;

   if( userp(ob) )        uid = getuid(ob);
   else if(stringp(ob))   uid = ob;
   else return 0;
   temp=previous_object(1);
if (userp(ob))
    {
//     if (wizhood(ob)=="(admin)") return 0;
     if (status=="(admin)" && wizhood(temp)!="(admin)" ) return 0;
     if (status=="(arch)" && (wizhood(temp)!="(admin)"&& wizhood(temp)!="(arch)")) return 0;
     if (status=="(wizard)" &&(wizhood(temp)!="(admin)"
                              && wizhood(temp)!="(arch)"
                              && wizhood(temp)!="(wizard)")) return 0;
    }               
   if( status == "(player)" )
     map_delete(wiz_status, uid);
   else
     wiz_status[uid] = status;
   wiz = keys(wiz_status);
   for(wizlist = "", i=0; i<sizeof(wiz); i++)
     wizlist += wiz[i] + " " + wiz_status[wiz[i]] + "\n";
   rm(WIZLIST);
   write_file(WIZLIST, wizlist);
   log_file( "static/promotion", capitalize(uid)
    + " become a " + status + " on " + ctime(time()) + "\n" );
   return 1;
}

string *get_wizlist() { return keys(wiz_status); }


int valid_read(string file, mixed user, string func)
{
        string euid, status, *path, dir;
        int i;
        
        if( !objectp(user) )
                error("TRUST_D->valid_read: Invalid argument type of user.\n");

        // Let user restore their save file
        if( func=="restore_object" ) {
                if( sscanf(file, "/data/%*s") && (
                      ( file == (string) user->query_save_file() )||
                      ( file == (string) user->query_save_file() + ".o" ) ) )
                  return 1;
        }
        
        if (    func != "read_file" &&
                func != "file_size" &&
                func != "stat" &&
                func != "read_bytes" &&
                func != "tail" &&
                func != "ed_start"
        ) return 1;
        
        // Get the euid and status of the user.
        if( !euid = geteuid(user) )
                return 1;
        status = get_status(user);

        if( euid==ROOT_UID ) return 1;
	if((file=="/u/"||file=="/u")&&wiz_level(status)>wiz_level("(immortal)"))		return 1;//        if( sscanf(file, "/u/" + euid + "/%*s") )
	if( sscanf(file, "/u/" + euid + "/%*s") || file=="/u/"+euid)                return 1;

        path = explode(file, "/");
        for(i=sizeof(path)-1; i>=0; i--) {
                dir = implode(path[0..i], "/");
                if( undefinedp(exclude_read[dir]) ) continue;
                if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
                if( member_array(status, exclude_read[dir])!=-1 ) return 0;
        }
/*	if( member_array(euid, trusted_read["/"])!=-1 ) return 1;	if( member_array(status, trusted_read["/"])!=-1 ) return 1;	for(i=sizeof(path)-1; i>=0; i--) {		dir = implode(path[0..i], "/");		if( undefinedp(trusted_read[dir]) ) continue;		if( member_array(euid, trusted_read[dir])!=-1 ) return 1;		if( member_array(status, trusted_read[dir])!=-1 ) return 1;	}
*/
        return 1;
}
/*
        string euid, status;
        euid = geteuid(user);
   status = get_status(user);
        log_file("read_files", sprintf("%s(%s) %ss %s.\n",euid,status,func,file));
*/
   


int valid_write(string file, mixed user, string func)
{
   string euid, status, *path, dir;
   int i;

   if( !objectp(user) )
     error("TRUST_D->valid_write: Invalid argument type of user.\n");
    if(valid_read(file,user,func)==0) return 0;  

   if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

   // Let user save their save file
   if( func=="save_object" ) {
     if( (sscanf(base_name(user), "/obj/%*s") ||
          sscanf(base_name(user), "/d/%*s") ||
         sscanf(base_name(user), "/u/tool/obj/%*s"))
     &&   sscanf(file, "/data/%*s")
     &&   ( file == (string)user->query_save_file() ||
               file == (string)user->query_save_file()+".o" ||
               file == (string)user->query_save_file()+".oo.o" ||
          file == ((string)user->query_save_file()+".oo") ))
return 1;
   }

   // Get the euid and status of the user.
   euid = geteuid(user);
   if( !euid ) return 0;
   status = get_status(user);

   if( euid==ROOT_UID ) return 1;

/*   if( sscanf(file, "/u/" + euid[0..0] + "/" + euid + "/%*s") )
     return 1; */

   if( sscanf(file, "/u/" + euid + "/%*s") ) {
     log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()),euid,status,func,file));
          return 1; 
        }

   path = explode(file, "/");

   // Check if we are excluded in one of the directories containing the file.
   for(i=sizeof(path)-1; i>=0; i--) {
     dir = implode(path[0..i], "/");
if( undefinedp(exclude_write[dir]) ) continue;
     if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
     if( member_array(status, exclude_write[dir])!=-1 ) return 0;
   }

   // And then check if we are trusted in one of the directories containing
   // the file.
   if( member_array(euid, trusted_write["/"])!=-1 ) 
   {
        log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
     return 1;
    }
   if( member_array(status, trusted_write["/"])!=-1 )
   {
        log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
     return 1;
    }
   if( path[0] == "u") return 0;
   for(i=sizeof(path)-1; i>=0; i--) {
     dir = implode(path[0..i], "/");
     if( undefinedp(trusted_write[dir]) ) continue;
     if( member_array(euid, trusted_write[dir])!=-1 )
       {
log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
         return 1;
        }
     if( member_array(status, trusted_write[dir])!=-1 )
       {
            log_file("FILES", sprintf("[%s] %s(%s) %ss %s.\n",ctime(time()), euid, status, func, file));
         return 1;
        }
   }

   log_file("FILES", sprintf("[%s] %s(%s) write attempt on %s failed.\n",ctime(time()),euid, status, file));
   return 0;
}


int valid_seteuid( object ob, string uid )
{
   if( uid==0 ) return 1;
   if( uid==getuid(ob) ) return 1;
   if( getuid(ob)==ROOT_UID ) return 1;
   if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
   if( wiz_status[uid] != "(admin)" && wiz_status[getuid(ob)] == "(admin)" )
   return 1;
   return 0;
}

