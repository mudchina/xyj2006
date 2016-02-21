inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIW"元始天尊"NOR, ({"yuanshi tianzun","tianzun", "master"}));
       set("long", "昆仑玉虚洞祖师爷，满头白发的老人，两眼炯炯有神。\n");
       set("title", HIW"道法"NOR);
       set("gender", "男性");
       set("age", 100);
        set("class", "shen");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 40);
       set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 150);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
        set("daoxing", 10000000);

       set_skill("spells",300);
        set_skill("force", 260);
        set_skill("dodge", 280);
        set_skill("parry", 300);
        set_skill("sword", 260);
        set_skill("xuanzong-force", 300);
        set_skill("lingyunbu", 270);
        set_skill("dashen-bian", 290);
        set_skill("kaitian-zhang", 250);
        set_skill("huntian-jian", 270);
        set_skill("literate", 300);
        set_skill("unarmed", 270);
        set_skill("yuxu-spells", 300);
        set_skill("wugou-jian", 280);
        set_skill("mace",270);
        map_skill("spells", "yuxu-spells");
        map_skill("dodge", "lingyunbu");
        map_skill("mace", "dashen-bian");
        map_skill("force", "xuanzong-force");
        map_skill("parry", "wugou-jian");
        map_skill("sword", "wugou-jian");
        map_skill("unarmed", "kaitian-zhang");
        
create_family("昆仑山玉虚洞", 1, "蓝");
setup();

        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/kunlun/obj/zhuxian")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="昆仑山玉虚洞") {
        if ((int)ob->query("daoxing") < 500000 ) {
        command("say 欲想成仙，道兄的道行是不是差了点？，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "反复无常，老夫不原再收你为徒了！\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 35) {
        command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("yuxu-spells", 1) < 150 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "对我玉虚仙法领会还不够深，现在收你你也很难领悟我的讲解，不如作罢！\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
       command("recruit " + ob->query("id") );
       ob->set("title", "元始天尊嫡传弟子"); 
    message("system", HIY"昆仑山玉虚洞又多了一个弟子  "+this_player()->name()+HIW"
                     昆仑山玉虚洞的势力加强了。\n"NOR,users());
        return;
        }
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shen");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
        return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n元始天尊微皱眉头，道：这家伙这么厉害，也罢！！！\n\n", environment());
        command("sigh");
        message("sound", "\n元始天尊身形一转，架起一朵莲花飞上天空。。。\n\n", environment());
        }

        destruct(this_object());
}
