#include <ansi.h>
inherit ROOM;
void confirm_dispose(string arg, object ob, object fabao_ob);
void create()
{
	set("short",HIG "宠物集市" NOR);
	set("long",@LONG
这里就是本国最大的宠物集市，你有什么宠物就可以
拿到这里来交换。
LONG
	);
	
	set("exits", ([ /* sizeof() == 2 */
 
]));
 set("objects", ([ /* sizeof() == 2 */
  //__DIR__"obj/shu" : 1,
]));
	setup();
}
void init()
{
add_action("do_sell","sell");
}
int do_sell(string arg)
{
 object ob = this_player();
   object pet_ob;
   string pet_id;
    
   if (!ob->query("pet/pet_id"))
      return notify_fail("你并没有宠物，来凑什么热闹？\n");
   pet_id=ob->query("pet/pet_id");
   if( !objectp(pet_ob=present(pet_id, ob)) && 
       !objectp(pet_ob=present(pet_id, environment(ob))))
      return notify_fail("你的宠物没和你一起来吗?\n");
      
   if(pet_ob->query("owner") != ob->query("id")) 
      return notify_fail("这......这个宠物好象不是你的耶！\n");
      
   write("你确定要把你的"+pet_ob->query("name")+"交换出去？(y/n)\n");
   input_to( (: confirm_dispose :), ob, pet_ob); 
   return 1;
}

void confirm_dispose(string arg, object ob, object pet_ob)
{
   string msg;
   int skl;
   if( arg == "y" || arg == "Y" ) 
     {
        if((int)pet_ob->query_skill("dodge",1) < 19 ||
           (int)pet_ob->query_skill("parry",1) < 19 ||
           (int)pet_ob->query_skill("unarmed",1) < 19)
          {
          write("你的宠物级别不够，不能用来交换。\n"); 
          return;
          }
        skl=COMBAT_D->skill_power(pet_ob, "unarmed", 1)/100
           +COMBAT_D->skill_power(pet_ob, "unarmed", 2)
           +COMBAT_D->skill_power(pet_ob, "dodge", 2);
        skl+=pet_ob->query("zhongcheng")+pet_ob->query("tonicity")+pet_ob->query("cool")-pet_ob->query("sloth")+pet_ob->query("combat_exp")+pet_ob->query("daoxing");
        write("参数："+skl+"\n"); 
        if (ob->query_temp("pet")==1)
               {
                ob->set_temp("pet",0);
                ob->delete_temp("ride/dodge");
               }
	ob->delete("pet");
msg=ob->name()+"在集市里卖掉了"+pet_ob->name()+"，得到"+skl+"点武学和"+COMBAT_D->chinese_daoxing(skl/2)+"道行。\n";
	message_vision(msg,pet_ob,ob);
	CHANNEL_D->do_channel(this_object(), "rumor",msg);
	destruct( pet_ob );
	
    }
  return;
}
