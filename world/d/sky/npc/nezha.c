// created 4/12/1998 by bbs
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
  set_name("ÄÄß¸", ({ "nezha santaizi", "nezha", "santaizi" }));
  set("title", "ÈıÌ³º£»áÖ®Éñ");
  create_family("Ïİ¿ÕÉ½ÎŞµ×¶´", 1, "µÜ×Ó");
  set("class", "xian");
  set("long", "Ò»Î»´½ºì³İ°×µÄÃÀÉÙÄê¡£\n");
  set("gender", "ÄĞĞÔ");
  set("age", 16);
  set("attitude", "heroism");
  set("rank_info/respect", "Ğ¡Ì«×Ó");
  set("rank_info/rude", "Èé³ôÎ´¸ÉµÄĞ¡¶ù");
  set("per", 40);
  set("str", 30);
  set("cor", 40);
  set("con", 40);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 2000);
  set("max_gin", 1800);
  set("max_sen", 3000);
  set("force", 2600);
  set("max_force", 4000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 5000);
  set("mana_factor", 120);
  set("combat_exp", 1500000);
  set("daoxing", 2000000);

  set_skill("spells", 180);
  set_skill("dao", 180);
  set_skill("unarmed", 170);
  set_skill("yinfeng-zhua", 180);
  set_skill("dodge", 180);
  set_skill("lingfu-steps", 170);
  set_skill("parry", 190);
  set_skill("force", 190);
  set_skill("huntian-qigong", 180);
  set_skill("spear", 170);
  set_skill("huoyun-qiang", 150);
  set_skill("blade", 170);
  set_skill("sword", 200);
  set_skill("qixiu-jian", 180);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spear", "huoyun-qiang");
  map_skill("parry", "huoyun-qiang");
  map_skill("sword", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
  set("inquiry", ([
	"name": "ÎÒÄËÍĞËşÌìÍõÈıÌ«×ÓÀîÄÄß¸ÊÇÒ²¡£",
	"here": "ÕâÀïÊÇÍĞËşÌìÍõ¸®¡£",
	"rumors": "ÓñµÛë··â¼ÒÑÏÎª½µÄ§´óÔªË§£¬ÔÚÏÂÎªÈıÌ³º£»áÖ®Éñ£¬×¨¹Ü½µÑı³ıÄ§¡£",
	"ÓñÊó¾«": "ÎŞµ×¶´µÄÓñÊó¾«£¿ÄÇÊÇÎÒµùµÄÒåÅ®¡£",
	"»ğ¼âÇ¹": "ËÍÈËÁË£¡",
	]));
  setup();
  carry_object("/d/obj/cloth/taijicloth")->wear();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/sword/qingfeng")->wield();
  if ("/d/obj/fabao/huntian-ling"->in_mud())
    carry_object("/d/obj/fabao/huntian-fake");
  else
    carry_object("/d/obj/fabao/huntian-ling");
  if ("/d/obj/fabao/qiankun-quan"->in_mud())
    carry_object("/d/obj/fabao/qiankun-fake");
  else
    carry_object("/d/obj/fabao/qiankun-quan");
}

void attempt_apprentice(object ob)
{
  if ((string)ob->query("family/family_name")=="Ïİ¿ÕÉ½ÎŞµ×¶´") {
	if(ob->query("obstacle/wudidong")=="done") {
		command("say ÆäÊµÎä¹¦²¢ÎŞÕıĞ°Ö®·Ö£¬ÖØÒªµÄÊÇÈËĞÄÉÆ¶ñ¡£");
		command("say "+RANK_D->query_respect(ob)+"¼ÈÈ»ÓĞĞÄÏòÉÆ£¬¿´ÔÚÎÒÃÃ×ÓµÄ·İÉÏ£¬¾ÍÊÕÏÂÄã°É¡£");
		command("recruit "+ob->query("id"));
	}
	else {
		command("say "+RANK_D->query_respect(ob)+"ÊÇÎŞµ×¶´µÄµÜ×Ó£¬°İÎÒ²»´óºÏÊÊ°É£¡");
		command("say "+RANK_D->query_respect(ob)+"ÈôÔ¸ÒâÑ§£¬¿´ÔÚÎÒÃÃ×ÓµÄ·İÉÏ£¬ÎÒµ½¿ÉÒÔµã²¦Ò»¶ş¡£");
	}
  }
  else {
  	command("say ÎÒ²»ÈÏÊ¶Äã¡£");
	command("sorry");
  }
}

int prevent_learn(object me, string skill)
{
  int myyaofa=me->query_skill("yaofa",1);

  if (skill == "dao") {
	if(myyaofa!=0) {
		command("sigh");
		command("say "+RANK_D->query_respect(me)+"ÑıÆøÌ«ÖØ£¬²»ÄÜÑ§µÀ¼ÒÏÉ·¨¡£");
		return 1;
	}
  }
  return 0;
}

void die()
{
  int i;
  object *inv;
  string msg;

  if(environment()) {
    msg="$NºŞºŞµØµÀ£ºĞ¡Ò¯ÎÒÕâ¾ÍÈ¥¸æÓù×´£¬ÓĞÖÖÄã¾ÍÔÚÕâ¶ùµÈ×Å£¡\n";
    msg+="$N»¯µÀ½ğ¹â£¬¾¶ÍùÄÏÌìÃÅ·½Ïò¶øÈ¥¡£\n\n";
    message_vision(msg, this_object(), this_player());
    inv=all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
      if (inv[i]->query("no_drop")) continue;
      do_drop(this_object(), inv[i]);
    }
  }
  destruct(this_object());
}

int do_drop(object me, object obj) 
{
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
            else {
                 message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n", undefinedp(obj->query_temp("unit"))? "¸ö":obj->query_temp("unit") ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
           else {
             message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n", obj->query("unit")), me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"ÒòÎªÕâÑù¶«Î÷²¢²»ÖµÇ®£¬ËùÒÔÈËÃÇ²¢²»»á×¢Òâµ½ËüµÄ´æÔÚ¡£\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}

void unconcious()
{
    die();
}
ÿ