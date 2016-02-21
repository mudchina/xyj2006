object connect()
{
        object login_ob;
        mixed err;
   
        err = catch(login_ob = new(LOGIN_OB));

        if (err) {
                write("现在有人正在修改使用者连线部份的程式，请待会再来。\n");
                write(err);
                destruct(this_object());
        }
        return login_ob;
}
mixed compile_object(string file)
{
        object daemon;

        if( daemon = find_object(VIRTUAL_D) )
                return daemon->compile_object(file);
        else
                return 0;
}
static void crash(string error, object command_giver, object current_object)
{
        efun::shout("系统核心发生一点小故障了。\n");
        efun::shout("系统核心告诉你：要当机了，自己保重吧！\n");
        log_file("static/CRASHES", MUD_NAME + " crashed on: " + ctime(time()) +
                ", error: " + error + "\n");
        if (command_giver)
                log_file("static/CRASHES",
                        sprintf( "this_player: %O\n", command_giver));
        if (current_object)
                log_file("static/CRASHES",
                        sprintf( "this_object: %O\n", current_object));
}
static string *update_file(string file)
{
        string *list;
        string str;
        int i;

        str = read_file(file);
        if (!str)
                return ({});
        list = explode(str, "\n");
        for (i = 0; i < sizeof(list); i++) {
                if (list[i][0] == '#') {
                        list[i] = 0;
                }
        }
        return list;
}
string *epilog(int load_empty)
{
        string *items;

        items = update_file(CONFIG_DIR + "preload");
        return items;
}
void preload(string file)
{
        int t1;
        string err;

        if (file_size(file + ".c") == -1)
                return;

        t1 = time();
        write("Preloading : " + file );
        err = catch(call_other(file, "??"));
        if (err)
                write(" -> Error " + err + " when loading " + file + "\n");
        else
                write(".... Done.\n");
                
}
void log_error(string file, string message)
{
        string name, home;
   
        if( find_object(SIMUL_EFUN_OB) )
                name = file_owner(file);

        if (name) home = user_path(name);
        else home = LOG_DIR;

        if(this_player(1)) efun::write("编译时段错误：" + message+"\n");
        
        efun::write_file(home + "log", message);
}
int save_ed_setup(object who, int code)
{
        string file;
  
    if (!intp(code))
        return 0;
    file = user_path(getuid(who)) + ".edrc";
    rm(file);
    return write_file(file, code + "");
}
int retrieve_ed_setup(object who)
{
   string file;
   int code;
  
    file = user_path(getuid(who)) + ".edrc";
    if (file_size(file) <= 0) {
        return 0;
    }
    sscanf(read_file(file), "%d", code);
    return code;
}
void destruct_env_of(object ob)
{
        if (!interactive(ob))
                return;
        tell_object(ob, "你所存在的空间被毁灭了。\n");
        ob->move(VOID_OB);
}
string make_path_absolute(string file)
{
        file = resolve_path((string)this_player()->query("cwd"), file);
        return file;
}
string get_save_file_name(string fname)
{
    return fname + "." + time();
}

string get_root_uid()
{
   return ROOT_UID;
}

string get_bb_uid()
{
   return BACKBONE_UID;
}

string creator_file(string str)
{
        return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}

string domain_file(string str)
{
        return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}

string author_file(string str)
{
        return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}
string standard_trace(mapping error, int caught)
{
    int i, s;
    string res;
    res = (caught) ? "错误讯息被拦截: " : "";
    res = sprintf("%s\n执行时段错误：%s\n程式：%s 第 %i 行\n物件: %s\n",
        res, error["error"],
        error["program"], error["line"],
        file_name(error["object"]));

    for (i=0, s = sizeof(error["trace"]); i < s; i++) {
                res = sprintf("%s呼叫来自：%s 的 %s() 第 %i 行，物件： %O\n",
                        res,
                        error["trace"][i]["program"],
            error["trace"][i]["function"],
            error["trace"][i]["line"],
            error["trace"][i]["object"] );
    }
CHANNEL_D->do_channel(this_object(), "sys",
               sprintf("%s 第 %i 行，物件：%s\n        %s",
               (undefinedp(error["program"])?
	       "(none)":error["program"]), 
	       error["line"],
               ( (undefinedp(error["object"]) || !error["object"])?
	       "(none)":file_name(error["object"])), 
    	       error["error"]));
    return res;
}
string error_handler( mapping error, int caught )
{
    if (this_player(1)) {
        this_player(1)->set_temp("error", error);
        tell_object(this_player(1), standard_trace(error, caught));
    }
    return standard_trace(error, caught);
}

// valid_shadow: controls whether an object may be shadowed or not
int valid_shadow( object ob ) { return 0; }

// valid_override: controls which simul_efuns may be overridden with
//   efun:: prefix and which may not.  This function is only called at
//   object compile-time
int valid_override( string file, string name )
{
        // simul_efun can override any simul_efun by Annihilator
        if (file == SIMUL_EFUN_OB || file==MASTER_OB)
                return 1;

        // Must use the move() defined in F_MOVE.
        if(((name == "move_object") || (name == "destruct")) && (file != F_MOVE))
                return 0;

    //  may also wish to protect destruct, shutdown, snoop, and exec.
        return 1;
}

// valid_seteuid: determines whether an object ob can become euid str
int valid_seteuid( object ob, string str )
{
    return (int)SECURITY_D->valid_seteuid( ob, str );
}

// valid_socket: controls access to socket efunctions
int valid_socket( object eff_user, string fun, mixed *info )
{
        return 1;
}

// valid_asm: controls whether or not an LPC->C compiled object can use
//   asm { }
int valid_asm( string file )
{
    return 1;
}

// valid_compile_to_c: controls whether or not an object may be compiled
//   via LPC->C
int valid_compile_to_c( string file )
{
    return 1;
}

// valid_hide: controls the use of the set_hide() efun, to hide objects or
//   see hidden objects
int valid_hide( object who )
{
    return 1;
}

// valid_object: controls whether an object loaded by the driver should
//   exist
int valid_object( object ob )
{
    return (!clonep(ob)) || inherits(F_MOVE, ob);
}

// valid_link: controls use of the link() efun for creating hard links
//   between paths
int valid_link( string original, string reference )
{
    return 0;
}

// valid_save_binary: controls whether an object can save a binary
//   image of itself to the specified "save binaries directory"
//   (see config file)
int valid_save_binary( string filename )
{
    return 1;
}

// valid_write: write privileges; called with the file name, the object
//   initiating the call, and the function by which they called it. 

int valid_write( string file, mixed user, string func )
{
        object ob;

        if( ob = find_object(SECURITY_D) )
                return (int)SECURITY_D->valid_write(file, user, func);

        return 0;
}

// valid_read: read privileges; called exactly the same as valid_write()
int valid_read( string file, mixed user, string func )
{
        return 1;
}

string object_name(object ob)
{
        if( ob ) return ob->name();
}

void create()
{
        write("master: loaded successfully.\n");
}

int valid_bind(object binder, object old_owner, object new_owner)
{
        if( userp(new_owner) ) return 0;
        if( geteuid(binder)==ROOT_UID ) return 1;
        if( clonep(new_owner) ) return 1;
        return 0;
}
