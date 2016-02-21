//jikao.c盘丝洞姬邑考传授琴艺
//2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int give_qin(object ob);
void create()
{
       set_name("姬邑考", ({"ji yikao", "ji","yikao"}));
       set("long",
"他面如满月，手姿俊雅，一表非俗，其风情动人。周文王之子,擅长琴艺,为
救文王孤身入朝歌献琴谢罪,为妲己所害,武王平定天下后被封为五斗星正神中
天北极紫微大帝,隐居在盘丝洞内,经常在这里抚琴。\n");
       set("title", MAG"中天北极紫微大帝"NOR);
       set("gender", "男性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "少年");
       set("per", 100);
       set("int", 40);
       set("max_kee", 10000);
//       set("max_gin", 2600);
       set("max_sen", 10000);
       set("force", 12000);
       set("max_force", 5800);
       set("force_factor", 500);
       set("max_mana", 8000);
       set("mana", 10000);
       set("mana_factor", 400);
       set("combat_exp", 5000000);
       set("daoxing", 6000000);
       set("eff_dx", 800000);
       set("nkgain", 350);
       set_skill("literate", 600);
       set_skill("unarmed", 260);
       set_skill("dodge", 300);
       set_skill("force", 280);
       set_skill("parry", 290);
       set_skill("sword", 300);
       set_skill("spells", 250);
       set_skill("whip", 300);
       set_skill("qin", 600);
       set_skill("pansi-dafa", 280);
       set_skill("lanhua-shou", 240);
       set_skill("jiuyin-xinjing", 270);
       set_skill("qingxia-jian", 270);
       set_skill("yueying-wubu", 280);
       set_skill("yinsuo-jinling", 300);
       set_skill("chixin-jian", 300);
       map_skill("spells", "pansi-dafa");
       map_skill("unarmed", "lanhua-shou");
       map_skill("force", "jiuyin-xinjing");
       map_skill("sword", "chixin-jian");
       map_skill("parry", "chixin-jian");
       map_skill("dodge", "yueying-wubu");
       map_skill("whip", "yinsuo-jinling");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: cast_spell, "ziqi" :),
                (: perform_action, "sword.haotan" :),      
}) );
       set("inquiry", ([
                "琴艺" : "琴有内外五形，六律五音，吟操勾剔，左手龙睛，右手凤目，按宫商
                角徵羽。又有八法，乃抹，挑，勾，剔，撇，托，敌，打，有六忌，有七不弹。",
		"琴" : "此琴乃太古遗音，乐而近雅，与诸乐大不相同。其中有八十一大调，五
		十一小调，叁十六等音。",
		"八法" : "八法，乃抹，挑，勾，剔，撇，托，敌，打。",
		"六忌" : "闻哀恸泣专心事，忿怒情怀戒欲惊。",
		"七不弹" : "疾风骤雨，大悲大哀，衣冠不正，酒醉性狂，无香近亵，不知音近
		俗，不洁近秽；遇此皆不弹。",
                "五韵" : "宫商角徵羽。",
                "七弦琴" : (: give_qin :),
                "qin" : (: give_qin :),
		]) );
   set("chat_chance",1);
   set("chat_msg", ({
   	CYN"音无平兮清心目，世上琴声天上曲；尽将千古圣人心，付与叁尺梧桐木！\n"NOR,
/*        CYN"邑考盘膝坐在地上，将琴放在膝上，十捐尖尖拨动琴弦，抚弄一曲，名曰："HIG"风入松"NOR+CYN"。
             “杨柳依依弄晚风，桃花半吐映日红；芳草绵绵铺锦绣，任他车马各西东。”
音韵幽扬，真如戛玉鸣球，万壑松涛，清婉欲绝。今人尘襟顿爽，恍如身在瑶池凤阙！\n"NOR,*/
        }));


create_family("盘丝洞", 1, "弟子");
setup();

  carry_object("/d/npc/obj/qin")->wield();//装备天魔琴
//  carry_object("/obj/loginload/mancloth1")->wear();
//  carry_object("/obj/loginload/linen")->wear();
  carry_object("/d/pansi/obj/qin");//携带七弦琴
  carry_object("/d/npc/obj/armor")->wear();
  carry_object("/d/npc/obj/pifeng")->wear();
}

void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="盘丝洞") {
   	 if (ob->query("obstacle/number") < 26) {
        command("say 这位" + RANK_D->query_respect(ob) + "你还是先出去闯荡一番吧！\n");
        command("sigh");
        return;
        }
        if (((int)ob->query("daoxing") < 1000000 )) {
        command("say " + RANK_D->query_respect(ob) +"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
        return;
}
/*if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 盘丝洞只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;}*/
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +"看在紫霞的面子上，我就收下你了。\n");
        command("recruit " + ob->query("id") );
        return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +"我不认识你吧。\n");
        return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "yaomo");
    ob->set("title", MAG"六指琴魔"NOR);
}

int give_qin(object ob)
{
   object who, me;
   who=this_player();
   me=this_object();

   if( (string)who->query("family/family_name")!="盘丝洞" ) {
     if( (int)who->query_temp("pending/ask_time") >= 3) {
        message_vision("$N突然跳起，恶狠狠的瞪着$n说：看来你是不想活了！\n", me, who);
        command("kill " + who->query("id"));
        return 1;
        }
     message_vision("$N斜斜地瞟了$n一眼，说：此不足为外人道也！\n", me, who);
     who->add_temp("pending/ask_time", 1);
     return 1;
   }
   if( (int)me->query("have") ){
     
     command("give qin to " + who->query("id"));
     me->delete("have");
     return 1;
   }
   message_vision("$N对$n无奈的一伸手，说：琴已发完了，你明日再来领吧。\n", me, who);
   return 1;
}
void die()
{
        if( environment() ) {
message("sound", "\n\n姬邑考怒道,你这厮怎地这生无礼！\n\n", environment());
message("sound", "\n说罢一抚琴弦,化作一道紫气冲天而去。。。\n\n", environment());
        }
        destruct(this_object());
}
