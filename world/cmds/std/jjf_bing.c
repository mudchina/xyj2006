// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

//jjf_bing.c...Weiqi 12/12/97.
//command to let jjf people get qin bing.

inherit F_CLEAN_UP;
 
int find_allbing(string str);
int find_mybing(object me, string str, int show_position);

int main(object me, string arg)
{
   string QINBING_FILE = "/obj/npc/qinbing.c";
   object qinbing;
   int max_bing = 0;
   int current_bing = 0;

   seteuid(getuid());

/*
   if (!wizardp(me))
     return notify_fail("测试中，目前只有巫师能用。\n");
*/

   if( arg == "find" )
   {//let wiz find all qinbing copies.
     if (!wizardp(me))
        return notify_fail("只有巫师才能用这个选项。\n");
     else return find_allbing(QINBING_FILE);
   }   

   if( (string)me->query("family/family_name") != "将军府" )
         return notify_fail("你并非朝廷武将，哪有资格领亲兵。\n");
   
   if(me->query("combat_exp") >= 500000)
   {
     max_bing = 4;
   }
   else if(me->query("combat_exp") >= 100000)
   {
     max_bing = 2;
   }
   else if(me->query("combat_exp") >= 50000)
   {
     max_bing = 1;
   }
   else max_bing = 0;

   if( max_bing < 1 ) 
         return notify_fail("你目前还没有资格领亲兵。\n");

   current_bing = find_mybing(me, QINBING_FILE, 0);
   //last 0 means do not show position.

   me->set_temp("jjf_current_bing", current_bing+1);

   if( (int)me-> query_temp("jjf_current_bing") > max_bing )
     return notify_fail("按你的级别，领亲兵的规格不能再高了。\n");

   //ready to get qin bing out...btw, let the player pay first.
   //1 gold each qin bing.
   if( (int)me->query("balance") < 10000)
   {
     return notify_fail("你现在已经发不出兵饷了，谁还跟你？\n");
   }
   //ok, the player has enough money...
   me->set("balance",  (int)me->query("balance")-10000);
   me->save();

   //now let's get the qing bing out.
   message_vision("只听$N大喝一声：来人啦！\n", me);
   qinbing = new(QINBING_FILE);
   qinbing->move(environment(me));
   qinbing->show(me);

       return 1;
}
 
int find_allbing(string str)
{
   object *list;
   int number;
   object where;
   int i, count;
   
   count = 0;

   if(!str) return 0;

   list = children(str);
   number = sizeof(list);

   if(number) 
   {
     for(i=0; i<sizeof(list); i++) 
     {
        write((int)(i+1)+". "+file_name(list[i])+" "+
          list[i]->query("name")+"("+list[i]->query("id")+") is at ");
        where=environment(list[i]);
        if(where) 
        {
          if(where->query("short")) 
          {
             write(where->query("short"));
          } 
          else 
          {
             write(where->short());
          }
          write("("+file_name(where)+"), " );
          write("owner_id: " + list[i]->query("owner_id") + "\n");
        } 
        else 
        {
          write("???, ");
          write("owner_id: " + list[i]->query("owner_id") + "\n");
        }
     }
   }
   
   count = number;
   write("\n共有" + count + "个亲兵。\n");
   return count;
}

int find_mybing(object me, string str, int show_position)
{
   object *list;
   int number;
   object where;
   int i, count;
   
   count = 0;

   if(!str) return 0;

   list = children(str);
   number = sizeof(list);

   if(number) 
   {
     for(i=0; i<sizeof(list); i++) 
     {
        if( (string)list[i]->query("owner_id") != (string)me->query("id") )
          continue;
        count++;
        if(!show_position) continue;

        //now also show position.
        write(list[i]->query("name")+"在");
        where=environment(list[i]);
        if(where) 
        {
          if(where->query("short")) 
          {
             write(where->query("short"));
          } 
          else 
          {
             write(where->short());
          }
          write("\n");
        } 
        else 
        {
          write("？？？");
          write("\n");
        }
     }
   }
   
   return count;
}


int help(object me)
{
    write(@HELP
指令格式: jjf_bing (巫师可用jjf_bing find) 
 
朝廷武将可领亲兵作为护卫或摆威风，其规格决定于该武将之级别。
当然所谓“兵无饷不行”，没有钱亲兵也不亲了。
可用whisper对亲兵下命令。例如，如果你的亲兵叫ttt-jia，用
whisper ttt-jia kill xiao er即可命令他杀店小二。

HELP
    );
   return 1;
}
 
