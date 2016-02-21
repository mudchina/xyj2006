inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("姜子牙", ({ "jiang ziya", "jiang", "ziya" }));
        set("title", "周朝开国宰相");   
        set("long", @LONG
    本名姜尚，在元始天尊门下修行多年，在助周朝夺得天下后返回昆
仑。
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

        set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 160);
set_skill("mace", 180);
       set_skill("dashen-bian", 180);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("spells", 150);
       set_skill("yuxu-spells", 150);
       set_skill("kaitian-zhang", 150);
       set_skill("xuanzong-force", 150);
       set_skill("lingyunbu", 150);
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("force", "xuanzong-force");
       map_skill("mace", "dashen-bian");
       map_skill("parry", "dashen-bian");
       map_skill("dodge", "lingyunbu");


        create_family("昆仑山玉虚洞", 2, "弟子");

        setup();
        carry_object("/obj/money/gold");
        carry_object("/d/kunlun/obj/dashenwhip")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("daoxing") < 150000 ) {
        command("say 道兄的道行差了些，又怎么能学我的鞭法呢？，" + RANK_D->query_respect(ob) + "还需多加努力才能学到真功夫。\n");
                return;
        }
        command("nod");
        command("say 这位仙兄有可造之才，我就收了你吧。\n");
message("system", HIY"昆仑山玉虚洞又多了一个弟子  "+this_player()->name()+HIW"
                     昆仑山玉虚洞的势力加强了。\n"NOR,users());
        command("recruit " + ob->query("id") );
        return; 
}
