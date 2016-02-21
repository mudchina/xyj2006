/*
        www/cgi-bin/finger.c
        Created by Ammy@YSZZ
        2001/04/13
        finger,is called at many places
*/      

#include <mudlib.h>
//inherit F_REMOVEANSI;

void create() { seteuid( getuid() ); }

string gateway(string arg) 
{

        object ob,body;
        int online,public_flag;
        string str,str_h,str_f,msg;
        string plan="",*plan_l;
        
        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        
        str =str_h;
        online = 0;

        if( sscanf(arg,"id=%s",arg) == 0)
                return "参数错误，请重新输入！";

        if (arg=="ammy")
                return str+="<div align=center><font color=red>没有这个玩家</font>&nbsp;&nbsp;["
                        +arg+"]<br><br><br>"+str_f;

        ob = new(LOGIN_OB);
        ob->set("id", arg);

        if( !ob->restore() ) 
        {
                destruct(ob); 
                return str+="<div align=center><font color=red>没有这个玩家</font>&nbsp;&nbsp;["
                        +arg+"]<br><br><br>"+str_f;
        }
        
        if( objectp(body = find_player(arg)) && geteuid(body)==arg ) 
        {
                online=1;
                public_flag = body->query("env/public")?1:0;
        } else 
        {
                body = LOGIN_D->make_body(ob);
                if( !body->restore() ) {
                destruct(body);
                return str+="<div align=center><font color=red>没有这个玩家</font>&nbsp;&nbsp;["
                        +arg+"]<br><br><br>"+str_f;
                        }
                public_flag = body->query("env/public")?1:0;
                destruct(body);
        }     
                
        str +="<div align=center><br>※&nbsp;"+MUD_NAME+"※玩家查询</div>";
        str += "<table border=0 width='400' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 width='100%' cellspacing=1 cellpadding=4>";        

        if (online) 
        {
                if( interactive(body)
                    && !body->query("env/invisibility") ) 
                    {
                    int idle=query_idle(body);
                    msg = sprintf("%s目前正在连线",body->name(1));
                    if(idle>59) 
                        msg+=sprintf("，已发呆 %d 秒钟", idle);
                    else 
                        msg+="中";
                    }   
        }    
        
        if (ob->query("plan"))
        {
                plan_l = explode(ob->query("plan"),"\n");
                for( int i=0;i<sizeof(plan_l);i++ ) 
                {
                        plan += sprintf("%s<br>",plan_l[i]);
                }
        }
        
        str += sprintf(
        "<tr bgcolor=whitesmoke><td>英文代号：</td><td>%s</td></tr>"
        "<tr bgcolor=whitesmoke><td>姓　　名：</td><td>%s</td></tr>"
        "<tr bgcolor=whitesmoke><td>权限等级：</td><td>%s</td></tr>"
        "<tr bgcolor=whitesmoke><td>电子信箱：</td><td>%s</td></tr>"
        "<tr bgcolor=whitesmoke><td>上次连线：</td><td>%s</td></tr>"
        "<tr bgcolor=whitesmoke><td>状　　态：</td><td>%s</td></tr>"
        "<tr bgcolor=whitesmoke><td>连线情况：</td><td>%s</td></tr>"    
        "<tr bgcolor=whitesmoke><td colspan=2>个人说明档：<br>"
        "<div align=right><table border=0 width=350><tr><td nowrap>%s</td></tr></table></div></tr>"
        ,
        ob->query("id"),
        ob->query("name"),
        SECURITY_D->get_status(arg),
        public_flag?"<a href='mailto:"+ob->query("email")+"'>"+ob->query("email")+"</a>":"不告诉你",
        ctime(ob->query("last_on")),
        (time() > ob->query("freeze_time"))?"正常":"休眠中,苏醒将在"+(ob->query("freeze_time")+3600-time())/3600+"小时后",
        online?  msg : "否",
        (!ob->query("plan"))?"〈暂时没有>":plan
        );

    destruct(ob);
    str += "</table></td></tr></table>";
// str =remove_ansi(str);
    str +=str_f;
    return str;
}
