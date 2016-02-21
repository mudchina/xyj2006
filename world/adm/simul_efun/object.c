// object.c

varargs int getoid(object ob)
{
        int id;

        if (!ob) ob = previous_object();
        sscanf(file_name(ob), "%*s#%d", id);
        return id;
}

// Get the owner of a file.  Used by log_error() in master.c.
string file_owner(string file)
{
    string name, rest, dir;

    if (file[0] != '/') {
        file = "/" + file;
    }
    if (sscanf(file, "/u/%s/%s/%s", dir, name, rest) == 3) {
        return name;
    }
    return 0;

}

// domain_file should return the domain associated with a given file.
string domain_file(string file)
{
        string domain;

        if( sscanf(file, "/d/%s/%*s", domain) )
                return domain;

        return ROOT_UID;
}

 string creator_file(string file)
 {
         string *path;

         path = explode(file, "/") - ({ 0 });
         switch(path[0]) {
                 case "adm":
                         if( file==SIMUL_EFUN_OB ) return "MudOS";
                         else return ROOT_UID;
                 case "cmds":
                         return ROOT_UID;
                 case "open":
                         return "Test";
                 case "u":
                 case "ftp":
                         if( this_player(1) && wizardp(this_player(1)) )

                                 return getuid(this_player(1));
                         // previous_object(0) is master object here.
                         else if( previous_object(1) )
                                 return geteuid(previous_object(1));
                         return "User";
                 case "www":
                         if(path[1]=="cgi-bin")
                                return ROOT_UID;
                        // added by ammy to permit post
                 case "d":
                         return "Domain";
                 case "obj":
                         if( this_player(1) )

                                 return getuid(this_player(1));
                         // previous_object(0) is master object here.
                         return "Domain";
                  default:
                         if( this_player(1) )
                                 return getuid(this_player(1));
                         else
                                 return "MudOS";

        }
}


// author_file should return the name of the author of a specific file.
string author_file(string file)
{
        string name;

        if( sscanf(file, "/u/%*s/%s/%*s", name) )
                return name;
        return ROOT_UID;
}

void destruct(object ob)
{
        if (ob) {
                if( previous_object() ) ob->remove( geteuid(previous_object()) );
                else ob->remove(0);
        efun::destruct(ob);  //put this inside the if(ob). mon 8/19/97
        }
}

// added by xuy.
int living(object ob)
{
        if(!ob) return 0;
        if (ob && ob->query_temp("disabled") )
                return 0;
        return efun::living(ob);
}
