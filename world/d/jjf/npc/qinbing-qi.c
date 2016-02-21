//created 6-9-97 pickle
//亲兵
 
inherit NPC;

void create()
{
  set_name("亲兵", ({"qin bing", "qin", "bing", "soldier", "qinbing"}));
  set ("long", @LONG
一个彪形大汉，看身上衣服大概是齐府的亲兵，齐王李建成的近身护卫。
LONG); 
  set("title", "齐王府");
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
  set("chat_chance", 7);
  set("inquiry", ([
        "name" : "问什么问？长着眼睛不会看哪？",
        "here" : "这儿就是醉星楼！造的可比对面那破房子强得多啦！",
        "rumors" : " 听说有人想来拆房子，哼！",
        "拆房子" : "哼，除非把老子打发了，否则谁也别想来这儿撒野！",
         ]) );
  setup();
 
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}
int accept_object(object me, object ob)
{
  object npc=this_object();
 
  if ((string)ob->query("name_recognized")!="齐府令箭")
    {
      command ("say 哈哈！老子最爱受人贿络了！");
      call_out("destroy", 1, ob);
      return 1;
    }
  call_out("leavehere", 2, npc, me);
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







