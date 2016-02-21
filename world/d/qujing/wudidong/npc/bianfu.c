// bianfu.c òùòğ¾«
// 9-18-97 pickle

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

/************************************************************/

// function and global variable declaractions

int attempt_apprentice(object me);
int recruit_apprentice(object me);
void transform();
string ask_me();
void transform_back();
void mie_kou(object me);

/************************************************************/

void create()
{

  set_name("Çîºº", ({"qiong han", "qiong", "han", "poor man","man"}));
  set("title", "ÆÕÍ¨°ÙĞÕ");
  set("long",
"Ëû¿´ÆğÀ´Ò»¸¶ÇîÀ§ÁÊµ¹µÄÑù×Ó£¬»ëÉíÃ»Ò»¼şÏóÑùµÄÒÂ·ş£¬Êİ¹Çá×á¾µÄ£¬\n"
"¾ÍÏóÈıÄêÃ»³Ô¹ıÒ»¶Ù±¥·¹ËÆµÄ¡£ËäËµ³¤°²³ÇÀïÕâÑùµÄÈË±È±È½ÔÊÇ£¬µ«Äã\n"
"¿´Ëû¾ÍÊÇ¾õµÃ²»Ë³ÑÛ¡£×ĞÏ¸¶ËÏêÒ»·¬£¬Äã·¢ÏÖÔ­À´ËûÈ«Éí³¤×ÅÒ»²ãµ­µ­\n"
"µÄÈ×Ã«¡£\n");
  set("combat_exp", 3000);
  set("daoxing", 500000);

  set("attitude", "peaceful");
  set("gender", "ÄĞĞÔ");
  set("age", 39);
  create_family("Ïİ¿ÕÉ½ÎŞµ×¶´", 2, "µÜ×Ó");

  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("stealing", 50);
  set_skill("spells", 80);
  set_skill("sword", 80);
  set_skill("qixiu-jian", 30);
  set_skill("yinfeng-zhua", 30);
  set_skill("lingfu-steps", 80);
  set_skill("force", 80);
  set_skill("yaofa", 30);
  set_skill("huntian-qigong", 30);

  set("str", 20);
  set("cor", 100);
  set("int", 20);
  set("spi", 30);
  set("cps", 100);
  set("per", 10);
  set("con", 40);
  set("kar", 20);
  
  set("env/wimpy", 70);

  set("max_kee", 400);
  set("max_sen", 400);
  set("force", 350);
  set("max_force", 350);
  set("mana", 350);
  set("max_mana", 300);
  set("inquiry", ([
                   "name": "Õâ¸ö¡­¡­ÎÒÕâÇîººµÄÃû×Ö¶ÔÄãÓÖÓĞÊ²Ã´ÓÃÁË£¿",
                   "here": "ÕâÀï£¿ÄãÎÊÎÒÎÒÎÊË­È¥£¿",
		   "rumors": "ÌıËµ×î½ü¸½½üÓĞĞ©ÀÏÊó¾«ÔÚ³¤°²³Ç³öÃ»¡£°¦¡£",
		   "ÀÏÊó¾«": "ÎÒÌıËµËûÃÇÊÇ¸öÊ²Ã´Ê²Ã´É½Ê²Ã´Ê²Ã´¶´µÄ£¬Ò²²»ÖªÕ¦»ØÊÂ¡£",
		   "Ïİ¿ÕÉ½": (: ask_me :),
		   "ÎŞµ×¶´": (: ask_me :),
                 ]) );  

  setup();
  carry_object("/d/obj/cloth/pobuyi")->wear();
}
/************************************************************/

// the menpai settings, but only useful after npc transforms.

int attempt_apprentice(object me)
{
  string myid=me->query("id");
  if (!query("wudidong_state")		// if not ready to accept dizi then return
   && !query("accept_dizi"))
	return 0;
  command("spank "+myid);
  command("say ²»´í²»´í¡£");
  command("say µ«ÄãÒª¾­µÃÆğ¿¼Ñé²ÅÄÜÕæÕıÑ§µ½ÎÒÎŞµ×¶´µÄ¸ßÉîÎä¹¦¡£");
  command("recruit "+myid);
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
/************************************************************/

// since this npc stands in the middle of chang an, he can't
// be in his normal Ñı¹Ö form. so he is usually a Çîºº until
// somebody asks THE question. hehe...

string ask_me()
{
    object me=this_player();

    if (me->query("family/family_name") == "Ïİ¿ÕÉ½ÎŞµ×¶´")
    {
	command("nod");
	command("recruit "+me->query("id"));
	return "ÕâÄã»¹ÓÃÎÊÎÒ£¿£¡";	// if already in wudidong, no point
    }
    if(!query("wudidong_state"))	// if not in bianfu form, ask person
    {					// whether they wanna join anyway.
	command("hehe");
	command("say Êµ»°¸æËßÄã°É£¡´óÒ¯ÎÒ¾ÍÊÇÎŞµ×¶´µÄÉÏÏÉ£¡");
	set("accept_dizi", 1);		// here, be ready to accept dizi
	command("say "+me->name()+"£¬Äã¿ÉÔ¸ÒâÈëÎÒÎŞµ×¶´£¿");
	command("recruit "+me->query("id"));
	call_out("mie_kou", 60, me);	// give him 5 min, if still not, Ãğ¿Ú
	return "ºÙºÙ£¬ÄãÈôÊÇ²»Ô¸£¬¿ÉÄª¹ÖÎÒĞÄºİÊÖÀ±£¡";
    }
    command("say ÈôÊÇÏë°İÎÒÎŞµ×¶´£¬¾¡¹ÜËµ£¡");	// if in bianfu form, recruit
    remove_call_out("transform_back");		// note one thing: our bianfu
    call_out("mie_kou", 60, me);		// will not transform back into
    return "·ñÔò¾Í±ğ¹ÖÎÒÉ±ÈËÃğ¿ÚÁË£¡";		// human coz he needs to kill
}
void transform()
{
  object weapon;
  if(!interactive())
    return;
  set_name("òùòğ¾«", ({"bian fu", "bianfu", "fu", "bat", "monster"}));
  set("title", "ÉÏÏÉ");
  set("long",
"ÕâÃ÷Ã÷ÊÇÒ»Ö»¾Ş´óµÄòùòğ£¬µ«²»ÖªÎªºÎ¾¹È»»áËµÈË»°£¡\n");
  set("combat_exp", 300000);
  set("daoxing", 500000);

  weapon=new("/d/obj/weapon/sword/changjian");
  weapon->move(this_object());
  command("wield sword");
  command("enable force huntian-qigong");
  command("enable unarmed yinfeng-zhua");
  command("enable spells yaofa");
  command("enable sword qixiu-jian");
  command("enable parry qixiu-jian");
  command("enable dodge lingfu-steps");
  set("wudidong_state", 1);
  message_vision(HIY"ÇîººÒ¡ÉíÒ»±ä£¬ÏÖÁËÔ­ĞÎ¡£Ô­À´ÊÇÖ»òùòğ£¡\n"NOR, this_object());
}
void mie_kou(object me)
{
    string myid=me->query("id");
    if (!interactive()) return;
    if (me->query("family/family_name") == "Ïİ¿ÕÉ½ÎŞµ×¶´")
    {
	command("pat "+myid);			// if he has bai in meantime
	command("say ²»´í£¬Ê¶Ê±ÎñÕß¿¡½Ü£¡");	// don't kill him, compliment him
	call_out("transform_back", 300);	// change back to human
	return;
    }
    if (!present(myid, environment()))
    {
	command("sneer");			// laugh at the cowards
	command("say ĞÒ¿÷"+me->name()+"ÁïµÃ¿ì¡£·ñÔò£¬ºß£¡ºß£¡ºß£¡");
	call_out("transform_back", 300);
	return;
    }
    if (!query("wudidong_state"))		// if still in human form
	transform();				// change into bianfu form to kill
    command("say "+me->name()+"£¬Äã¼ÈÈ»Ö´ÃÔ²»Îò£¬ÄÇ¾ÍÄÉÃüÀ´°É£¡");
    command("kill "+myid);			// kill!
    call_out("transform_back", 180);		// assume fight over in 3 min
    return;					// at which time change back
}
void transform_back()
{
    object weapon, me=this_object();

    if(!query("wudidong_state"))		// if already in human form, no point.
	return;
    if(!interactive())				// can't change back if fainted
    {						// give another 30 sec
	remove_call_out("transform_back");
	call_out("transform_back", 30);
	return;
    }
    if (is_fighting())				// obviously can't change back
    {						// if still fighting, so give
	remove_call_out("transform_back");	// it another 3 min
	call_out("transform_back", 180);
	return;
    }
  if (objectp(weapon=present("sword", me)))
    destruct(weapon);
  message_vision(HIY"$NÒ¡ÉíÒ»±ä£¬±ä³ÉÁË¸öÇîºº£¡\n"NOR, this_object());
  set_name("Çîºº", ({"qiong han", "qiong", "han", "poor man","man"}));
  set("title", "ÆÕÍ¨°ÙĞÕ");
  set("long",
"Ëû¿´ÆğÀ´Ò»¸¶ÇîÀ§ÁÊµ¹µÄÑù×Ó£¬»ëÉíÃ»Ò»¼şÏóÑùµÄÒÂ·ş£¬Êİ¹Çá×á¾µÄ£¬\n"
"¾ÍÏóÈıÄêÃ»³Ô¹ıÒ»¶Ù±¥·¹ËÆµÄ¡£ËäËµ³¤°²³ÇÀïÕâÑùµÄÈË±È±È½ÔÊÇ£¬µ«Äã\n"
"¿´Ëû¾ÍÊÇ¾õµÃ²»Ë³ÑÛ¡£×ĞÏ¸¶ËÏêÒ»·¬£¬Äã·¢ÏÖÔ­À´ËûÈ«Éí³¤×ÅÒ»²ãµ­µ­\n"
"µÄÈ×Ã«¡£\n");
  set("combat_exp", 3000);
  set("daoxing", 500000);

  set("attitude", "peaceful");
  delete("wudidong_state");
  command("enable parry none");
  command("enable dodge none");
  command("enable force none");
  command("enable sword none");
  command("enable spells none");
  return;
}
ÿ
