// laozhang.c
//

inherit NPC;

void create()
{
  set_name("老张", ({"lao zhang","zhang", "old zhang"}));
  set("title","农民");
  set("gender", "男性" );
  set("age", 75);
  set("long", "
人说七十古来稀。老张今年七十有五，可身子骨儿真棒。下田干活儿从不要人帮忙。
村中人叫他老张不知有多少年了，叫的连他自己都不记得真名了。平日他总是笑容满面
的，但不知为什么，今天却不停地唉声叹气。\n");
  set("combat_exp", 50000);
  set("attitude", "peaceful");
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set("per", 25);
  set("max_kee", 250);
  set("max_gin", 300);
  set("max_sen", 300);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
  object ob;
  
  ::init();
  set("chat_chance", 7);
  set("inquiry", ([
		   "name" : "我就是老张，村里的老寿星。呵呵呵。。。",
		   "here" : "这里是张家村，家家户户都姓张。",
		   "rumors" : " 最近有好多大老鼠在村里跑来跑去，就连猫儿也不敢抓。幸亏不偷粮，否则。。。",
		   "老鼠" : "老汉活了这七十多年，还真没见过这肥壮的老鼠。怕不是成了精吧！",
		   "唉声叹气" : "老汉倒霉啊！昨儿个被个铁骷髅碰断了犁头，叫我怎么做农活儿呀！",
		   "铁骷髅" : "铁骷髅？老汉断了犁头你不说安慰安慰，来跟老汉要东西？年青人太不懂事啦！唉。。。",
		   "犁头" : "犁头对门张铁匠那儿有。可是叫我哪里去凑这五十两白银哪！",
		   ]) );
  
  set("chat_msg", ({
    "老张哭道：我可怜的犁头啊！你才跟了老汉三十年不到，怎么就夭折啦！天哪！我不活啦！呜呜。。。\n",
    "老张骂道：这些老鼠虽大，就吓倒我了？没那么容易！懒猫，还不去捉耗子，今天别想晚饭了！\n",
    "老张吓得面如土色，喊道：那，那，那是什么？老鼠？！啊～～～救命啊～～～喊着就向炕上跳去。\n",
  }) );
}
int accept_object(object me, object ob)
{
  object skull;
  
  if ((string)ob->query("id")!="li tou") {
    command("say 这怎么可以？折杀老汉了。");
    return 0;
  }
  else {
    if (query_temp("received_litou")==1) {
      command("thank "+ me->query("id"));
      command("say 多谢了。刚才有位善士施给老汉一把犁头，这一把我就不敢要了。");
      command("say 老汉生来穷命，不敢有这许多奢侈。这把犁头老汉实实在在生受不起。");
      command("say "+RANK_D->query_respect(me) +"这份善心，老汉领了。");
      command("say 这封信是我断犁头那天晚上在桌上发现的，对" +RANK_D->query_respect(me) + "或许有用，拿去看看吧。");
      carry_object("/d/qujing/wudidong/obj/skin");
      command("give skin to "+ me->query("id"));
      command("say 信里好像还有秘密，"+RANK_D->query_respect(me)+ "不妨仔细找找。");
      command("sigh");
      command("say "+ RANK_D->query_respect(me) + "莫嫌老汉多嘴。前途险恶，可要保重了。");
      add_temp("received_litou", 1);
      return 0;
    }
    else {
        if(query_temp("received_litou")<1 || !query_temp("received_litou")) {
          command("jump " + me->query("id"));
          command("say 这位" + RANK_D->query_respect(me) + "真是我的救星！实在太感谢了！");
          command("say 老汉也没什么可谢的。这里有个铁骷髅，这两天老有人来打听。想来总有点原因。");
          command("say " + RANK_D->query_respect(me) + "若是不嫌弃，就请收下吧。");
          carry_object("/d/qujing/wudidong/obj/skull");
          command("give skull to " + me->query("id"));
          command("say 这骷髅好像跟个老鼠精有点关系，详情老汉就不清楚了。");
          command("sigh");
          command("say "+ RANK_D->query_respect(me) + "莫嫌老汉多嘴。前途险恶，可要保重了。");
          add_temp("received_litou", 1);
   	  return 1;
        }
        command("say 多谢"+RANK_D->query_respect(me)+"的好意，不过老汉已经有一把新犁头了。");
        return 0;
    }
  }
}
