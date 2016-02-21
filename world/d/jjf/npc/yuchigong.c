//created 5-20-97 pickle
 
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("尉迟恭", ({"yuchi gong", "yuchi", "gong", "yuchigong", "jingde", "yuchi jingde", "yuchijingde", "master", "shifu"}));
  set ("long", @LONG
尉迟恭，字敬德，乃是唐太宗手下猛将。排为隋唐时第
十二条好汉。起初他是反王刘武州殿前元帅，后因兵败
降唐。他惯使一条点钢枪，且喜使一对雌雄竹节钢鞭。
LONG);
 
  set("title", "开国元勋");
  set("gender", "男性");
  set("age", 43);
  set("str", 45);
  set("per", 15);
  set("int", 20);
  set("cor", 50);
  set("cps", 40);
  set("combat_exp", 1400000);
  set_skill("spear", 120);
  set_skill("force", 150);
  set_skill("dodge", 150);
  set_skill("parry", 120);
  set_skill("mace", 180);
  set_skill("jinglei-mace", 150);
  set_skill("yanxing-steps", 120);
  set_skill("bawang-qiang", 100);
  set_skill("lengquan-force", 150);
  set_skill("unarmed", 120);
  set_skill("changquan", 100);
  map_skill("mace", "jinglei-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "jinglei-mace");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 1500);
  set("max_kee", 4000);
  set("force", 1000);
  set("max_force", 2500);
  set("force_factor", 100);
 
  create_family("将军府", 2, "蓝");
  setup();
 
  carry_object("/d/obj/weapon/spear/gangqiang");
  carry_object("/d/obj/weapon/mace/malemace")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  command("say 老夫手重，若是伤人反而不美了。\n");
  return 0;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  int kar=me->query_kar();
  int effstr=(int)(me->query("str")+me->query_skill("unarmed",1)/10-2);

  if ((effstr< 25) || (int)me->query_con()<20)
    {
      command("say 这"+myname+"手无缚鸡之力，不配作我徒弟！");
      return 0;
    }
  if ((int)me->query("cps") < 20 && (int)me->query_cor()<20)
    {
      command("say 这"+myname+"胆子还不如只老鼠！");
      return 0;
    }
  command("say 要想拜我为师，倒也不难。只需将那醉星楼拆了就行！\n");
  me->set("pending/jjfbai尉迟恭", 1);
  return 1;
}
int accept_object(object me, object ob)
{
  string myname=RANK_D->query_rude(me), thing=(string)ob->query("id");
  object book, npc=this_object();
  int kar=me->query_kar(), diff;
 
  if ((string)ob->query("name_recognized")!="醉星楼柱子")
    {
      command ("say 这是什么破烂？");
      call_out("dropthing", 1, thing);
      return 1;
    }
  if (me->query("pending/jjfbai尉迟恭"))
    {
      command ("nod");
      command ("say "+myname+"果然有两下子，老夫就收下你吧！");
      me->delete("pending/jjfbai尉迟恭");
      command ("recruit " + me->query("id") );
      call_out("destroy", 1, ob);
      return 1;
    }
  else
    {
      call_out("destroy", 1, ob);
      if (!me->query("mark/jjf拜魏徵无望"))
	  {
	    command("hehe");
	    command("say 这截柱子恐怕是你捡来的吧？");
	    command("say 就凭你这点本事，也砸的了醉星楼？");
	    return 1;
	  }
      command ("thumb" +me->query("id"));
      command ("say "+myname+"果然有两下子！");
      diff=35-kar;
      if(random(diff*diff)>4)
	return 1;
      command("say 看来"+myname+"跟老夫有缘，而且又帮我出了一口恶气。");
      command("say 这本跟随老夫多年的拆招秘诀就送给你吧！");
      book=new("/d/obj/book/parrybook2");
      message_vision(npc->query("name") + "给$N一本"+book->query("name"), me);
      book->move(me);
      return 1;
    }
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
void dropthing(string thing)
{
  command("drop "+thing);
  return;
}













