// message.c
#include <ansi.h>
#include <tomud.h>
#include <dbase.h>
#define MAX_MSG_BUFFER 500
static string *msg_buffer = ({});

string prompt()
{
        string p;
        string prompt, path;
        mixed list;
        mapping my;

        // 区别tomud显示方式和zmud
        if (arrayp(list = query_temp("tell_list")) &&
            sizeof(list) > 1)
        {
                  if ( this_object()->query_temp("tomud"))
                        p = HIG "> " NOR;
                else
                        p = HIG "<有信息>" NOR;
        }
        else
        {
                if ( this_object()->query_temp("tomud"))
                        p = HIY "> " NOR;
                else
                        p = "";
        }

        if (! stringp(prompt = query("env/prompt")))
                return p;

        switch (prompt)
        {
        case "time":
                p = HIC + ctime(time())[11..18] + p;
                break;
        case "date":
                p = HIC + ctime(time())[0..9] + p;
                break;
        case "mud":
                p = HIC + NATURE_D->game_time() + p;
                break;
        case "hp":
                if ( this_object()->query_temp("tomud"))
                        p = HIG + sprintf("%d/%d", query("jing"), query("qi")) + p;
                else
                {
                                       // tomud客户端激活hp状态栏
                      my = query_entire_dbase();
                      p = TMI("statu " + sprintf("精%d气%d精力%d内力%d食%d水%d潜能%d经验%d",
                             my["jing"], my["qi"], my["jingli"], my["neili"],
                             my["food"], my["water"], my["potential"] - my["learned_points"],
                             my["combat_exp"]) + p);
               }
                break;
        case "path":
                if (! wizardp(this_object()) || wiz_level(this_object()) < 3)
                        break;
              if (! stringp(path = query("cwd")))
              {
                     path = "/";
                     set("cwd", path);
              }
                // p = HIC + path[0..<2] + p;
                p = HIC + path[0..<2] + HIC "/ " NOR;
                break;
        default:
                p = prompt + p;
                break;
        }

        return p;
}




int receive(string str)
{
    if (!str) return 1;
        if( stringp(str) ) {
    if( interactive(this_object()) ) {
    if( this_object()->query_temp("big5") )
      str = (string)LANGUAGE_D->toBig5(str);
    }
     return efun::receive(str);
     }return 0;
}
void receive_message(string msgclass, string msg)
{
    string subclass, *ch;
    if( !interactive(this_object()) ) {
        this_object()->relay_message(msgclass, msg);
        return;
    }
    if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
        switch(subclass) {
            case "channel":
                if( !pointerp(ch = query("channels"))
                ||  member_array(msgclass, ch)==-1 )
                    return;
                    if (!this_object()->query_temp("tomud"))
                            {
                                     if (! query("chann/" + msgclass))
                                           msg = PTEXT(msg);  // 默认往公共窗口扔频道信息
                             }
                break;
            case "outdoor":
                if( !environment() || !environment()->query("outdoors") )
                    return;
                break;
            default:
                error("Message: Invalid Subclass " + subclass + ".\n");
        }
    }
    if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
        return;
    if( in_input(this_object()) || in_edit(this_object()) ) {
        if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
            msg_buffer += ({ msg });
    } else
        receive( msg );
}
void write_prompt()
{
    if( sizeof(msg_buffer) ) {
        receive(BOLD "[输入时暂存讯息]\n" NOR);
        for(int i=0;
 i<sizeof(msg_buffer);
 i++)
            receive(msg_buffer[i]);
        msg_buffer = ({});
    }
    write("> ");
}

//  temp "snoop-big5" 需要在 snoop.c里面控制
void receive_snoop(string msg)
{
        if ( msg && msg!="" && msg[0]!='%' ){
            if( this_object()->query_temp("snoop-big5"))
            if( this_object()->query_temp("big5")){
                efun::receive(msg);
                return;
             }else
                msg=LANGUAGE_D->Big52GB(msg);
                receive("%" + msg);
        }
}

