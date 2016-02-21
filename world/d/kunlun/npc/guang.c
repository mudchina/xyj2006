inherit NPC;
inherit F_MASTER;

string ask_mieyao();
string ask_cancel();

void create()
{
        set_name("广成子", ({ "guang chengzi", "guang", "master" }));
        set("title", "元始天尊大弟子");   
        set("long", @LONG
元始天尊大弟子。
LONG);
        set("gender", "男性");
        set("age", 55);
        set("attitude", "peaceful");
        set("rank_info/self", "本仙");
        set("class", "shen");
    
    set("max_kee", 1000);
        set("max_gin", 600);
           set("max_sen", 1000);
        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 75);
        set("max_mana", 1000);
        set("mana", 2000);
        set("mana_factor", 55);
        set("combat_exp", 750000);

        set("eff_dx", 150000);
        set("nkgain", 300);

        set_skill("literate", 200);
       set_skill("unarmed", 190);
       set_skill("dodge", 190);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("sword", 200);
       set_skill("spells", 200);
       set_skill("yuxu-spells", 200);
       set_skill("kaitian-zhang", 200);
       set_skill("xuanzong-force", 200);
       set_skill("huntian-jian", 190);
       set_skill("lingyunbu", 200);
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("force", "xuanzong-force");
       map_skill("sword", "huntian-jian");
       map_skill("parry", "huntian-jian");
       map_skill("dodge", "lingyunbu");

        set("inquiry", ([
           "cancel": (: ask_cancel :),
//"降妖": (: ask_mieyao :);
                ]) );

        create_family("昆仑山玉虚洞", 2, "弟子");

        setup();
        carry_object("/obj/money/gold");
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
        if (((int)ob->query_skill("yuxu-spells", 1) < 140 )) {
                command("say " + RANK_D->query_respect(ob) + "你的玉虚仙法还不够等级，再去练练吧。\n");
                return;
        }
        command("nod");
        command("say 这位仙兄有可造之才，我就收了你吧。\n");

        command("recruit " + ob->query("id") );
        return; 
}

string ask_mieyao()
{
    object who=this_player();
        
    if((string)who->query("family/family_name")=="昆仑山玉虚洞") {
      command("say 灭妖除魔，乃我仙家修炼之道。");
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
