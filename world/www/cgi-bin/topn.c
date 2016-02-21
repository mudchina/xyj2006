/*
	www/cgi-bin/top.c
	Created by Ammy@YSZZ
	2001/04/13
	在线高手排行榜
*/	

#include <mudlib.h>

inherit F_CLEAN_UP;
//inherit F_REMOVEANSI;

int top_list(object ob1,object ob2);
int get_score(object ob);

string gateway(string arg)
{
        
	object *list,*ob;
        int i, j;
	string str,str_h,str_f;

	str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        str =str_h;
        
	str +="<div align=center><br>※&nbsp;"+MUD_NAME+"※在线高手排行榜</div>";
        str += "<table border=0 width='600' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 width='100%' cellspacing=1 cellpadding=4>";        
        
      	ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
      	list = sort_array(ob, (: top_list :));

	str += "<tr bgcolor='whitesmoke' align=center>";
	str += "<td width=50>名次</td><td algin=center width=200>高&nbsp;&nbsp;&nbsp;&nbsp;手</td>";
	str += "<td width=300>门&nbsp;&nbsp;&nbsp;&nbsp;派</td><td width=50>评价</td>";
	str += "</tr>";
	
        for (i = 0 ;i < 10 ; i++) 
        {
        	if( i >= sizeof(list)||!list[i]->query("id")) 
        		str += "<tr bgcolor='whitesmoke' align=center><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td></tr>";
                else 
                {             
                	str += sprintf(
                	"<tr bgcolor='whitesmoke' align=center>"
                	"<td>%s</td>"
                	"<td align=left><a href=finger?id=%s>%s&nbsp;[%8s]</a></td>"
                	"<td>%s</td>"
                	"<td>%d</td>"
                	"</tr>",
                		chinese_number(i+1),
				lower_case(list[i]->query("id")),
                		list[i]->query("name"),
                		capitalize(list[i]->query("id")),
                		list[i]->query("family")?list[i]->query("family/family_name"):"普通百姓",
       				get_score(list[i])
       			);
                }
        }
	str +="</table></td></tr></table>";	
	str +=str_f;
	return str;
}

int top_list(object ob1, object ob2)
{
      	int score1,score2;
        score1 = get_score(ob1);
        score2 = get_score(ob2);
      	return score2 - score1;
}

int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

        reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++) {
                        tlvl += skills[ski[i]];
                        }  // count total skill levels
        score = 5*tlvl/(i+1);
        score += ob->query("max_force")/10;
        score += ob->query("max_mana")/10;
        score += 10*(ob->query("str") + ob->query("int") + ob->query("spi") + ob->query("con"));
        score += (int)ob->query("combat_exp")/5000;
        score -= 20*ob->query("PKS");
        return score;
}


