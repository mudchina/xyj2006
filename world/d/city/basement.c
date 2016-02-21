// basement.c

#include <ansi.h>
inherit ROOM;

object treasure_box;
object findbox();
void create ()
{
  object box;
  set ("short", "钱庄地下室");
  set ("long", @LONG
  
一间戒备森严的地下室，专门提供寄存服务。你可以在
这里寄存(jicun)物品，价格公道，不论物品贵贱，一律
每小时白银一两。若逾期不取(qu)，物品没收后以每样
纹银十两的低价公开出售(pick box)。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : "/d/city/bank",
]));
  set("no_clean_up",1);
  set("no_magic",1);
  set("no_fight",1);
  
  set("objects",([
   __DIR__"npc/zhudachang" :1,
]));  

  
  setup();

    
}

object findbox()
{
  if(treasure_box && environment(treasure_box)==this_object()) 
    return treasure_box;
   treasure_box=new(__DIR__"obj/shopbox");
  treasure_box->move(this_object());
  return treasure_box;  
}    

void init()
{
  add_action("do_jicun","jicun");
  add_action("do_qu","qu");
  add_action("do_pick","pick");
}

int do_jicun(string arg)
{
   object me=this_object();
   object who=this_player();
   object box;
   string box_mark;
   int limit;
   int deposit_time,value,afford;
   if (!treasure_box=findbox()) 
      return notify_fail("对不起,本钱庄暂停营业!\n");
   if (!arg) return notify_fail("你要寄存什么东西?\n");
   if (sscanf(arg,"%s for %d",arg,deposit_time)!=2) return notify_fail("你要寄存什么东西?\n");
   box=present("deposit box",who);
   if (!box) return notify_fail("你身上没有这样东西。\n");
   if (deposit_time>24 || deposit_time<1 ||!intp(deposit_time)) 
      return notify_fail("本钱庄寄存的时限只能是一至二十四小时!\n");
   box_mark=box->query("mark");
   if (!box_mark || box_mark!=arg) return notify_fail("你身上没有这样东西。\n");
   limit=(int)who->query_temp("jicun_limit");
   if (limit && limit>4) return notify_fail("对不起,每个人最多只能寄存五个盒子。\n");
   if (mapp(treasure_box->query("goods/"+arg)))
      return notify_fail("本钱庄已经寄存着同样标记的铁盒了,请换个标记再寄存。\n");
   value=deposit_time*100;
   if( !(afford=who->can_afford(value)) )  
     {
         write("你没有足够的钱。\n");
         return 1; 
     }   
   else if( afford == 2 )  
     {
         write("你没有足够的零钱，而银票又没人找得开。\n");
         return 1;
      }
   treasure_box->set("goods/"+arg+"/box",box);
   treasure_box->set("goods/"+arg+"/time",time()+deposit_time*3600);
   treasure_box->set("goods/"+arg+"/box_owner",who->query("id"));
   message_vision("$N寄存铁盒一只，期限"
                +CHINESE_D->chinese_number(deposit_time)+"小时。\n",who); 
   if (!treasure_box->query("goods/number")) treasure_box->set("goods/number",0);
   treasure_box->add("goods/number",1);
   box->move(treasure_box);
   who->start_busy(1);
   who->pay_money(value);
   who->add_temp("jicun_limit",1);
   return 1;
}

int do_qu(string arg)
{
   object box,me,who,deposit_box;
   mapping goods;
   string *goods_keys;
   int goods_number,i,flag=0;
   string box_owner;
   who=this_player();
   me=this_object();
   treasure_box=findbox();
   if (!treasure_box) return notify_fail("对不起,本钱庄暂停营业!\n");
   if (!arg) return notify_fail("你想取回什么?\n");
   if (!treasure_box->query("goods/number")) return notify_fail("本钱庄还没有人寄存过东西。\n");
   goods_keys=keys(treasure_box->query("goods"));
   goods_number=sizeof(goods_keys);
   if (goods_number<1) return notify_fail("本钱庄还没有人寄存过东西。\n");
   for (i=0;i<goods_number;i++)
     {
       if (goods_keys[i]==arg) flag=1;
     }
   if (!flag) return notify_fail("本钱庄没有人寄存过这个东西!\n");
   box_owner=treasure_box->query("goods/"+arg+"/box_owner");
   if (box_owner!=who->query("id")) return notify_fail("你没有寄存过这样东西!\n");
   box=treasure_box->query("goods/"+arg+"/box");
   if (!box=present(box,treasure_box)) 
       return notify_fail("你寄存的东西已经超过期限,被公开出售掉了!\n");   
   box->move(who);
   message_vision("$N取出一个铁盒。\n",who);
   who->add_temp("jicun_limit",-1);
   treasure_box->delete("goods/"+arg);
   treasure_box->add("goods/number",-1);    
   return 1;
}

int do_pick(string arg)
{
   object box,me,who,deposit_box;
   mapping goods;
   string *goods_keys,str;
   int goods_number,i,deposit_time,afford,value;
   who=this_player();
   me=this_object();
   if (!arg ||arg!="box") return 0;
   treasure_box=findbox();
   if (!treasure_box)
     return notify_fail("对不起,本钱庄暂停此种营业!\n");
   if (!treasure_box->query("goods/number")) return notify_fail("本钱庄暂时还没有可以公开出售的物品。\n");
   goods_keys=keys(treasure_box->query("goods"));
   goods_number=sizeof(goods_keys);
   value=2000;
   if( !(afford=who->can_afford(value)) )  
      {
        write("你没有足够的钱。\n");
        return 1; 
      }   
   else if( afford == 2 )  
      {
        write("你没有足够的零钱，而银票又没人找得开。\n");
        return 1;
      }  
   for (i=0;i<goods_number;i++)
    {
      str=goods_keys[i];
      deposit_time=treasure_box->query("goods/"+str+"/time");
      if (deposit_time<time())
        {
          box=treasure_box->query("goods/"+str+"/box");
          if (str!="number" && box=present(box,treasure_box))
          {
            message_vision("$N买下一只超过寄存期限的铁盒!\n",who);
            box->move(who);
            treasure_box->delete("goods/"+str);
            treasure_box->add("goods/number",-1);
            who->pay_money(value);
            return 1;
          } 
        }   
    }      
   message_vision("本钱庄暂时还没有可以公开出售的物品。\n",who);   
   return 1;  
}  
  
int clean_up()
{
      return 0;
}
  
