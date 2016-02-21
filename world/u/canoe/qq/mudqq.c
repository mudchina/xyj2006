// by canoe 2001-03-27
#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me,string arg)
{
        object ob;
        string* f_ids;
        mapping friends;
        string str,s1,s2;
        string myid;
        int i;

        friends = me->query("qq");
        myid=me->query("id");
        if(!arg) 
        {
                if(!friends 
                || !mapp(friends)
                ||  (sizeof(friends) == 0))
                        return notify_fail(HIR"    你的MUD_QQ上并没有加入过好友。\n"NOR);
                f_ids = keys(friends);
                write(HIR+"\t※──────你现在的朋友──────※\n"+NOR);
                str = "";
                for(i=0;i<sizeof(f_ids);i++)
                {
				ob=find_player(f_ids[i]);
            		str += "\t  "+HIG+friends[f_ids[i]]+"("+capitalize(f_ids[i])+")"+NOR;
				if (!ob || (ob->query("env/invisibility") && wizardp(ob) )) 
                        str += NOR CYN+"\t离    线  \n"+NOR;
				else
                        str +=NOR HIW+"\t在    线   \n"+NOR;
                }
                write(str);
                write(HIR+"\t※──────────────────※\n"+NOR);
                return 1;
        }
        if(sscanf(arg,"%s %s",s1,s2) ==2)
        {
                if(s1 == "-a")
                {
          if( !(ob = find_player(s2))
	  ||	!living(ob)
	  ||	!ob->is_character()
	  ||    ob->query("env/invisibility")   )
	    return notify_fail("没有这个人，无法添加好友名单！\n");
                        if(myid == s2)
                                return notify_fail("没这个必要吧！\n");
                        if(sizeof(friends)>15)
                                return notify_fail("你的好友名单太多了，请删掉些不常用的好友!\n");
                        if(me->query("qq/"+s2))
                        return notify_fail(ob->query("name")+"已经是在你的好友名单内！\n");
                        if(ob->query_temp("renzheng/"+myid)) return notify_fail("你已经向对方发送过请求了！\n");
                        if(ob->query("env/qq_no")) return notify_fail("对方拒绝加入好友，请通知对方unset qq_no！\n");
                        if(ob->query("env/qq_renzheng")) {
                        write("对方需要认证，你已经向"+ob->query("name")+"发出了认证请求！\n"); 
                        tell_object(ob,BLINK HIW+me->query("name")+"["+capitalize(myid)+"]向你发出认证请求！请使用mudqq -r 通过认证.\n"+NOR);
                        ob->set_temp("renzheng/"+myid,me->query("name"));
                      //  me->set_temp("qqadd/"+ob,ob->query("name"));
                        return 1;
                        }
                        else me->set("qq/"+s2,ob->query("name"));
                        write("你将"+ob->query("name")+"加入好友名单！\n");
                        if(living(ob))
                        tell_object(ob,BLINK HIG+me->query("name")+"["+capitalize(myid)+"]把你加入他的好友！\n"+NOR);
                        ob->set("qqof/"+myid,me->query("name"));
                        return 1;
                }
                else if(s1 == "-d")
                {
                        if(!objectp(ob = find_player(s2))
                        ||    ob->query("env/invisibility") )
                                return notify_fail("没这个人！\n");
                        if(!me->query("qq/"+s2))
                        return notify_fail("你没这个好友！\n");
                        me->delete("qq/"+s2);
                        write(HIG"你把"+ob->query("name")+"从好友名单中删掉了！\n"NOR);
                        return 1;
                }
                else if(s1=="-r")
                {
                 if( !(ob = find_player(s2))
	            ||	!living(ob)
	            ||	!ob->is_character()
	            ||    ob->query("env/invisibility")   )
	    return notify_fail("没有这个人，无法通过认证！\n");
	    if(!me->query_temp("renzheng/"+s2) ) return notify_fail("对方并没有向你发送过请求！\n");
            if(me->query("qq/"+s2))
                      return notify_fail(ob->query("name")+"已经是在你的好友名单内！\n");
             if(living(ob)){
             tell_object(ob,BLINK HIG+me->query("name")+"["+capitalize(myid)+"]已经通过了你的身份认证！\n"+NOR);  
             me->delete_temp("renzheng/"+s2);
             write(HIG+"你通过了"+ob->query("name")+"的认证请求！\n"+NOR);
             ob->set("qq/"+myid,me->query("name"));         
                        return 1;
                         }
                 }
        }
        write("用法:qq [-a|-d|-t] name\n");
        return 1;
} 

int help(object me)
{
   
        write(@HELP
指令格式 : mudqq [-a|-d|-r] [<某人>]
用这个命令可以让你查看或加,减好友。
-a <某人>: 添加某人为好友
-d <某人>: 从好友名单中删除某人
-r <某人>: 在对方向你发出认证请求时,用此命令通过对方认证请求.
不加参数 : 显示你的所有好友在线状况.

HELP
    );
    return 1;
}


