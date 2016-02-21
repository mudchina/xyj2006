//jingwei.c
//created by vikee 2000.11

inherit NPC;
int fill_sea();
int do_sui(string arg);

void create()
{
 set_name("精卫", ({"jing wei","jing"}));
 set("long", "一只传说中的鸟，填海的精卫。\n");
 set("combat_exp", 2000);
 set("attitude", "friendly");
 seteuid(getuid());
 set("attitude","heroism");
 set("chat_chance",20);
 set("chat_msg", ({
        "精卫长叹到：这茫茫东海，什么时候才能填平？\n",
         "精卫擦了擦额头的汗，一副无精打采的样子。"
         }));
         
 set("inquiry", ([
         "填海": (: fill_sea :),
         "fill sea":(: fill_sea :),
         ]));
 setup();
}

int fill_sea()
{
        object who=this_player();
  if ( (who->query("combat_exp")<10000) || (who->query("daoxing") < 15000 ) || (who->query("live_forever")!=1 )
    {
    return "填海可是个危险的事，你的功力不够，冒然填海会去送死的。\n";
    }
  else
    {
    who->set_temp("condition_ok", 1);
    return "你要打算填海可以跟我一起去(sui jing wei).\n";
    }
    
}

void init()
{
  add_action("do_sui", "sui jing wei");
}

int do_sui(string arg)
{
object who=this_player();
who->command("follow jing wei");
}

