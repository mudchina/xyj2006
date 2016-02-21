
#include <ansi.h>

inherit NPC;

string ask_pantao();

void create()
{
        set_name("赤脚大仙", ({"chijiao daxian","daxian"}));
        set("long", @LONG

一个懒懒散散的老头儿，正光着脚四处游荡。
他看上去忠厚老实，大概一骗(pian)就上当。
LONG);

        set("attitude", "peaceful");
        
    set("combat_exp", 500000);
  set("daoxing", 800000);


        set("age", 50);
        set("per", 22);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("class", "xian");
        set("rank_info/respect", "老神仙");
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 50);
        set("max_mana", 800);
        set("mana", 800);
        set("mana_factor", 50);


        set_skill("spells", 120);
        set_skill("taiyi", 120);
        set_skill("force",120);
        set_skill("zhenyuan-force",120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("baguazhen", 120);
        set_skill("unarmed", 120);
        set_skill("wuxing-quan", 120);
        set_skill("staff",110);
        set_skill("fumo-zhang",120);
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("dodge", "baguazhen");
        map_skill("unarmed", "wuxing-quan");
        map_skill("staff", "fumo-zhang");
        map_skill("parry", "fumo-zhang");
        setup();
        carry_object("/d/obj/cloth/baipao")->wear();
       set("inquiry", ([
                "name"     : "老夫赤脚大仙是也。",
                "here"     : "这就是天界啦。",
                "pantao" : (:ask_pantao:),
                "蟠桃会" : (:ask_pantao:),
         ]) );

        set("chat_msg", ({
            "赤脚大仙叹道：怎么还没到开蟠桃会的日子？老夫都等不及了。\n",
            (: random_move :),
            (: random_move :),
            (: random_move :),
        }) );
        set("chat_chance", 10);
}
void init()
{
  object ob;
  ::init();
  this_player()->delete_temp("ask_chijiao_daxian");
  add_action("do_pian","pian");
 
}
string ask_pantao() {
  this_player()->set_temp("ask_chijiao_daxian",1);  
  return "蟠桃大会召开在即，老夫蒙王母见招，去赴蟠桃嘉会。";
}

int do_pian(string arg) {
  object me=this_object();
  object liar=this_player();
  object letter;

  string *msg=
   ({"听说王母娘娘和玉帝母子失和，王母不高兴，决定今年蟠桃会不开了。",
     "你知道吗？托塔李天王和他儿子搞官倒，玉帝很生气，正派太白金星调查呢。",
     "下界有个叫什么的家伙，居然一夜间赚到了一千年的道行，肯定有ＢＵＧ！",
     "昨天如来佛被一个只有一千法力的凡夫俗子打败了，真丢脸！",
     "听说下界又有人搞ＰＫ啦，大仙不去看看热闹？",
     "听说有个叫围棋的竟然论证出了１＋１＝３的道理，厉害厉害。",
  });
  if (arg!="daxian" && arg!="chijiao daxian") 
     return notify_fail("你想骗谁？\n");
  
  if (me->query_temp("just_pian")) 
     return notify_fail("骗人的话说的太多就不灵了，待会儿再说。\n");
  me->set_temp("just_pian",1);
  call_out("remove_pian",5,me);

  if (!liar->query_temp("ask_chijiao_daxian")) {
    message_vision("$N神秘兮兮的对$n说：“"+msg[random(sizeof(msg))]+
          "”\n",liar,me);
    if (random(2)) {
      command("ah");
      command("say 竟有此事？当真是天下之大，无其不有。");
      command("sigh2");
    } else {
        command("laugh");
        command("say 你这"+RANK_D->query_rude(liar)+
          "又来哄我，天下哪有此事，不信不信。");
        command("shake");
      }
    return 1;
  }
  liar->command("say “大仙有所不知。玉帝着"+RANK_D->query_self(liar)+ 
                "五路邀请列位，先至通明殿下演礼，后方去赴宴。”");
  if (liar->name()==me->name()) {
    command("hmm");
    command("say 你变做老夫模样，又说这等言语，莫非其中有诈？！待我禀明玉帝，再作道理。");
    command("wave");
    message_vision(HIY"$N手一指，召来一朵云彩，高高兴兴地坐了上去，\n再吹一声口哨，随之往上冉冉地升起。。。\n\n"NOR,me);
    destruct(me);
    return 1;
  }
  
  command("ok");   
  command("say 常年就在瑶池演礼谢恩，如何先去通明殿演礼，方去瑶池赴会？");
  command("shrug");
  message_vision(HIY"$N手一指，召来一朵云彩，高高兴兴地坐了上去，\n再吹一声口哨，随之往上冉冉地升起。。。\n"NOR,me);
  letter=new(__DIR__"obj/letter");
  if (letter->move(liar))
    message_vision(HIY"$N走得匆忙，袍袖内不慎落下张纸片，$n眼明手快，一把接住，揣在怀里。\n"NOR,me,liar);
  destruct(me);
  return 1;
}

void remove_pian(object me) {
  me->delete_temp("just_pian");
}
