//created 6-9-97 pickle
//亲兵

#include <ansi.h>
inherit NPC;
string ask_me(object me);

void create()
{
  set_name("亲兵", ({"qin bing", "qin", "bing", "soldier", "qinbing"}));
  set ("long", @LONG
一个彪形大汉，看身上衣服大概是建府的亲兵，乃是高祖
第三子李元吉的近身护卫。他除了保护李元吉外似乎还管
发散钱财吃喝。
LONG); 
  set("title", "建王府");
  set("gender", "男性");
  set("age", 25);
  set("combat_exp", 80000);
  set_skill("blade", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("wuhu-blade", 60);
  map_skill("blade", "wuhu-blade");
  set("max_sen", 200);
  set("max_kee", 300);
  set("inquiry", ([
        "name" : "问什么问？长着眼睛不会看哪？",
        "here" : "这儿就是醉星楼！造的可比对面那破房子强得多啦！",
        "rumors" : " 听说有人想来拆房子，哼！",
        "食物" : "如果是良民，可以领些包子去。",
        "钱财" : "如果是良民，可以领些银子去。",
        "包子" : (: ask_me :),
        "baozi" : (: ask_me :),
        "银子" : (: ask_me :),
        "silver" : (: ask_me :),
        "拆房子" : "哼，除非把老子打发了，否则谁也别想来这儿撒野！",
         ]) );
  setup();
 
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}
int accept_object(object me, object ob)
{
  object npc=this_object();
 
  if ((string)ob->query("name_recognized")!="建府令箭")
    {
      command ("say 哈哈！老子最爱受人贿络了！");
      call_out("destroy", 1, ob);
      return 1;
    }
  call_out("leavehere", 1, npc, me);
  return 1;
}
string ask_me(object me)
{
  return("可以从我这里领到(ling)包子或银子。");
}
void init()
{
  add_action("do_ling", "ling");
}
int do_ling(string arg)
{
  object me=this_player(), npc=this_object(),ob;
  int kar=me->query_kar(), diff=kar-10;
  string player=me->query("id");

  if (!arg || (arg != "baozi" && arg != "包子" && arg != "silver" && arg!="银子"))
    return notify_fail("你想要什么？\n");
  if ((string)me->query("family/family_name") == "将军府")
    {
       me->add_temp("jjf/醉星楼要东西", 1);
       switch(me->query_temp("jjf/醉星楼要东西"))
         {
           case(1):
             {
                command("slap "+player);
                command("say 呔！二位王爷最恨的就是将军府弟子！给我滚！");
                message_vision(CYN"亲兵飞起一脚踢在$N屁股上，将$N踢出门外。\n"NOR, me);
                me->move("/d/city/center");
                return 1;
             }
           case(2):
             {
                command("slap "+player);
                command("say 莫要敬酒不吃吃罚酒！再来一次可别怪老子不客气了！");
                message_vision(CYN "亲兵飞起一脚踢在$N屁股上，将$N踢出门外。\n" NOR, me);
                me->move("/d/city/center");
                return 1;
            }
           default:
             {
                command("say 又是你！老子看你实在不顺眼，去死吧！");
                kill_ob(me);
                return 1;
            }
          } 
   }
  if ((string)me->query("title") != "普通百姓")
    {
      command("sneer "+player);
      command("say 混帐！有本事的自己干活去！");
      return 1;
    }
  if (arg == "baozi" || arg == "包子")
    {
      if (me->query("kee") < 40 || me->query("sen") < 40)
	return notify_fail("你太累了，挤不到亲兵边上。看来包子拿不到了。\n");
      ob=new("/d/obj/food/baozi");
      ob->move(npc);
      command("say 好吧，就赏你个包子吧！别忘了是谁给你的好处！");
      me->receive_damage("kee", 40-kar);
      me->receive_damage("sen", 40-kar);
      message_vision("$N费尽九牛二虎之力，被挤得浑身酸痛，才从人群中挤到亲兵面前。\n",me);
      command("give bao to "+player);
      return 1;
    }
  if (diff < 5)
    {
      command("slap "+player);
      command("say 老子看着你这"+RANK_D->query_rude(me)+"就不顺眼！银子没你的份！");
      return 1;
    }
  if (me->query("kee") < 60 || me->query("sen") < 60)
    return notify_fail("你太累了，挤不到亲兵边上。看来银子拿不到了。\n");

  if( (int)npc->query("time") > 10 ) 
    return notify_fail("亲兵一拱手，说：今天的银子发完了，明天再来吧。\n");


  npc->add_money("silver", 2*(int)diff/5);
  command("say 好吧，就赏你俩钱儿！别忘了是谁给你的好处！");
  npc->add("time", 1);
  me->receive_damage("kee", (40-kar)*2);
  me->receive_damage("sen", (40-kar)*2);
  message_vision("$N费尽九牛二虎之力，被挤得浑身酸痛，才从人群中挤到亲兵面前。\n",me);
  command("give silver to "+player);
  return 1;
}
void leavehere(object npc, object me)
{
  command("ah");
  command("say 既然齐王有急事，我这就去办！");
  command("thank "+me->query("id"));
  command("go northwest");
  destruct(npc);
  return;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
