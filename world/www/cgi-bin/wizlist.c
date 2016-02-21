/*
        www/cgi-bin/wizlist.c
        Created by Ammy@YSZZ
        2001/04/13
        巫师列表，可以显示连线情况以及备注等（留待扩充）
*/      

#include <mudlib.h>

//inherit F_REMOVEANSI;
inherit F_CLEAN_UP;

mapping levels=([
        "(admin)"       :       "天    神",
        "(arch)"        :       "大 巫 师",
        "(wizard)"      :       "巫    师",
        "(apprentice)"  :       "客座巫师",
        "(immortal)"    :       "小 巫 师",
        "(elder)"       :       "纪律总管",
]);
 
int level(mixed, mixed);    
string query_time(int time);

void create() { seteuid( getuid() ); }

string gateway(object me, string arg)
{
        string *list;
        int i, j,inv=0;
        string str, time_str,str_h,str_f;
        object ob, body;
       // string *task=explode(read_file("/adm/etc/wizjob"),"\n");        

        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        str =str_h;

        str+="<br><div align=center>※&nbsp;"+MUD_NAME+"※ 巫师列表<br>";
        str += "<table border=0 width='95%' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 width='100%' cellspacing=1 cellpadding=4>";

        str +=sprintf("
        <tr>
          <td align=center bgcolor='#fafafa' nowrap><b>中文名</b></td>
          <td align=center bgcolor='#fafafa' nowrap><font 
          color='#339900'>英文名</font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> 等级
            </font> </td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> 状态
            </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> 离线时间 
            </font></td>
          //<td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> 备注 </font></td>
        </tr>"
        );        

        list = sort_array(SECURITY_D->query_wizlist(),(: level :));

        for(i=0;i<sizeof(list);i++){
          if(list[i]=="ammy") continue;
          inv=0;
          ob=new(LOGIN_OB);
          ob->set("id", list[i]);
          ob->restore();

          if(objectp(body=find_player(list[i])) && !body->query("env/invisibility"))
          {
           time_str=sprintf(
           "<td width=40 align=center><font color=orange>连线</font></td><td width=180>%s</td>"
           , query_time(body->query_temp("temp_time")));
           inv=1;
          } 
          else 
          time_str=sprintf(
          "<td width=40 align=center><font color=black>离线</font></td><td width=180>%s</td>"
          , query_time(ob->query("last_on")));
          
          str+=sprintf(
          "<tr bgcolor='whitesmoke'>"
          "<td>%s</td>"
          "<td align=center><a href=finger?id=%s>%s</a></td>"
          "<td align=center>%s</td>"
          "%s"
          "<td  align='center'>%s</td></tr>",
                         ob->query("name"), 
                         list[i],
                         list[i],
                         levels[SECURITY_D->get_status(list[i])], 
                         time_str,"<br>"); 
          destruct(ob);
        }
        str+=sprintf("</table></td></tr></table><div align=right>%s现在共有%s名巫师&nbsp;&nbsp;&nbsp;&nbsp;</div>", MUD_NAME, chinese_number(sizeof(list)-1));
        str+=str_f;
        return str;
}

string query_time(int time)
{
        string str;
        int day, hour, min;
        
        time=time()-time;
        
        str="";
        day=time/86400;
        hour=time%86400/3600;
        min=time/60%60;
        if(min<1)
                min=1;
        if(day)
                str+=sprintf("%s天", chinese_number(day));
        if(day<10 && hour)
                str+=sprintf("%s小时", chinese_number(hour));
        if(!day && hour<20 && min)
                str+=sprintf("%s分钟", chinese_number(min));
        return str;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob2) - wiz_level(ob1);
        return ob1 > ob2?-1:1;
}
