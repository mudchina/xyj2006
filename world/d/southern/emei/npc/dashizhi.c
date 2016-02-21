//created by greenwc
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void create()
{
  set_name("如来佛祖", ({"rulai fo", "rulai", "fo"}));
  set("long", "大慈大悲灵山雷音古刹佛祖多陀阿伽陀如来佛爷。\n");
//人并称西方三神。
//LONG);
set("title", "佛祖多陀阿伽陀");
  set("gender", "男性");
  set("age", 400);
  set("str", 40);
  set("per", 40);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
       set_skill("literate", 300);
        set_skill("spells", 300);
        set_skill("buddhism", 300);
        set_skill("unarmed", 300);
        set_skill("jienan-zhi", 300);
        set_skill("dodge", 300);
        set_skill("lotusmove", 300);
        set_skill("parry", 300);
        set_skill("force", 300);
        set_skill("lotusforce", 300);
        set_skill("staff", 300);
        set_skill("lunhui-zhang", 300);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
                        (: perform_action, "hammer", "pudu" :),
	}) );
           set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
        set("force", 40000);
        set("max_force", 20000);
        set("force_factor", 1000);
        set("max_mana", 30000);
        set("mana", 60000);
        set("mana_factor", 1500);
        set("combat_exp", 20000000);
	set("daoxing", 10000000);

        create_family("南海普陀山", 1, "佛祖");
  setup();

        carry_object("/d/nanhai/obj/nine-ring")->wield();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

int accept_fight(object me)
{
  command("say 施主玩笑了\n");
return 0;
}

int attempt_apprentice(object ob)
{
	string myname=RANK_D->query_respect(ob);
            if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say 我佛门神通广大，" + RANK_D->query_respect(ob) + "欲成正果，先入我门。\n");
return 0;
}
if (((int)ob->query_skill("buddhism", 1) < 100 )) {
      command("say 施主对佛法的研究还不够精深！");
return 0;
}
if (ob->query("obstacle/number") < 26) {
        command("say 这位" + RANK_D->query_respect(ob) + "你还是先出去闯荡一番吧！\n");
        command("sigh");
        return 0;
        }
	command("pat " + ob->query("id") );
	command("say 好！这才是我佛门的好弟子。只要多加努力，定可早成正果。\n");
	command("recruit " + ob->query("id") );
ob->set("title", HIY"慈光普渡佛祖"NOR);
        return 0; 
}

void die()
{
        if( environment() ) {
        message("sound", "\n\n如来佛祖摇头叹道：冤孽！真是冤孽！n\n", environment());
        command("sigh");
        message("sound", "\n如来佛祖驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
}

	destruct(this_object());
}

