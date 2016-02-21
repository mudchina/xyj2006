/*
	www/cgi-bin/who.c
	Created by Ammy@YSZZ
	2001/04/13
	在线用户列表，可以加参数-l显示详细情况
*/	

#include <net/daemons.h>
#include <net/macros.h>

//inherit F_REMOVEANSI;
inherit F_CLEAN_UP;

int sort_user(object,object);
void create() { seteuid(getuid()); }

string gateway(string arg) 
{
	string *option, fname = "";	
        string str,str_h,str_f; 
        object *list,ob;
        int i,j,ppl_cnt, cnt;
	int opt_long;
	        
        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        
        str =str_h;
        str +="<br><br><div align=center>※&nbsp;"+MUD_NAME+"※目前在线的玩家</div>";
        str += "<table border=0 width='95%' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 width='100%' cellspacing=1 cellpadding=4>";

	ob = filter_array(objects(), (: userp :));
	list = sort_array(ob, (: sort_user :));
	
	if (arg=="-l") 	opt_long=1;
	else opt_long=0;	
        
        ppl_cnt = 0;
        cnt = 0;
        
        if( opt_long) 
        {
                i = sizeof(list);
                while( i-- ) {
                        if( !environment(list[i]) ) continue;
                        if( wizardp(list[i]) && list[i]->query("env/invisibility")) continue;                        

                        if (interactive(list[i])) ppl_cnt++;
                        else cnt++;
                        str +="<tr bgcolor='whitesmoke'>";
			
                        str += sprintf("<td>"+
                        	"%20s&nbsp;%s&nbsp;%s&nbsp;%s&nbsp;%s&nbsp;[%s]</td>"
                        	"<td><a href=finger?id=%s>查询</a></td></tr>",
                                RANK_D->query_rank(list[i]),
                                " ",
				list[i]->query("bang/bang_nick")?
				list[i]->query("bang/bang_name")+list[i]->query("bang/bang_nick"):
				"无帮派人士",
                                list[i]->query("title"),
                                list[i]->query("name"),
                                list[i]->query("id"),
                                list[i]->query("id")
                        );
                }
		str +="</table></td></tr></table>";
        } 
	else 
	{
		i=sizeof(list);
		while(i--) 
		{
        	        if( !environment(list[i]) ) continue;
         	       if( wizardp(list[i]) && list[i]->query("env/invisibility") ) continue;
			if (ppl_cnt%3 ==0)
			str +="<tr bgcolor='whitesmoke'>";
        	        str += sprintf("<td>"+
       	 	        "<a href=finger?id=%s>%12s&nbsp;[%8s]</a></td>",list[i]->query("id"),list[i]->name(1),capitalize(list[i]->query("id")));
			str +=ppl_cnt%3==2?"</tr>":""; 
			ppl_cnt++;
        	} 
               		
		i=ppl_cnt;
        	if (i%3 !=2 && i%3 !=0) {
        	for (j=0;j<(i%3)+1;j++)
        	{
        		str +="<td>&nbsp;</td>";
        	}}
        	if (i%3 ==2)
        		str +="<td>&nbsp;</td>";
		str +="</table></td></tr></table>";
        }				

        
        str +="<div align=right><br>№<font color=red>"+CHINESE_D->chinese_number(ppl_cnt)+ "</font>位使用者连线中";
	str +="&nbsp;&nbsp;详细情况查询请<a href=who?-l>点这儿</a>&nbsp;&nbsp;&nbsp;&nbsp;</div>";
        str = str;
        str += str_f;
        return str;
}


int sort_user(object ob1, object ob2)
{
        string name1, name2;;
        reset_eval_cost();
        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob2)
                        - wiz_level(ob1);

        name1 = ob1->query("family/family_name");
        name2 = ob2->query("family/family_name");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
