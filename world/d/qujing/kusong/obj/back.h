#include <ansi.h>

void back(object ob)
{
        object where=environment(this_object());
        object hong=new("/d/qujing/kusong/npc/honghaier");
        object tieshan=new("/d/qujing/firemount/npc/princess.c");
         if(  present("jin che",where)  
         || present("huo che",where) || present("shui che",where) ||
            present("tu che",where) )
                return ;
          tieshan->move(where);
          hong->move(where);
          message_vision(HIC"忽然红孩儿出现在你的面前。\n"NOR,ob);
          message_vision(HIC"红孩儿大惊失色：谁毁了我的五行车。\n"NOR,ob);
          hong->kill_ob(ob);
          tieshan->kill_ob(ob);
          ob->set_temp("done",1);
          return ;
}
