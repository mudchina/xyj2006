// Changed by sjmao  09-11-97
//changed by take 8-12-2001

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
int rank_me();
string expell_me(object me);



void create()
{
       set_name("ÁúÅ®", ({"long nu","gongzhu","long","princess"}));

	set("long","×ÏÔÆ¹¬Ö÷ÈË£¬ÁúÍõµÄÅ®¶ù£®\n");
       set("gender", "Å®ÐÔ");
       set("age", 20);
	set("int", 25+random(5));
        set("title", "×ÏÔÆ¹«Ö÷");
       set("attitude", "peaceful");
        set("combat_exp", 350000);
  set("daoxing", 100000);

       set("rank_info/respect", "¹«Ö÷µîÏÂ");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 900);
       set("max_sen", 700);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 500);
       set("mana", 400);
       set("mana_factor", 30);
       set_skill("literate", 80);
       set_skill("unarmed", 100);
       set_skill("dodge", 120);
       set_skill("force", 80);
       set_skill("parry", 100);
       set_skill("fork", 80);
       set_skill("spells", 100);
        set_skill("seashentong", 80);
        set_skill("dragonfight", 80);
        set_skill("dragonforce", 80);
        set_skill("fengbo-cha", 100);
        set_skill("dragonstep", 120);
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");

        set("inquiry", ([ "Àë¹¬": (: expell_me :),
                "leave": (: expell_me :), 
				         "Ö°Î»": (: rank_me :),
				]) );

    create_family("¶«º£Áú¹¬", 2, "Ë®×å");
	setup();

        carry_object("/d/obj/cloth/pinkskirt")->wear();
	carry_object("/d/sea/obj/yincha")->wield();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "¶«º£ÁúÉñ")
		return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
        if( (string)me->query("family/family_name") == "¶«º£Áú¹¬"){
                if( exp <= 100000 ){
                        me->set("title", HIR"¶«º£Áú¹¬"HIY"Ñ²µîÏº±ø"NOR);
                 } else if(exp <= 1000000 ){
                        me->set("title", HIR"¶«º£Áú¹¬"HIY"Ñ²º£Ò¹²æ"NOR);
                  } else if(exp < 2000000 ){
                        me->set("title", HIR"¶«º£Áú¹¬"HIY"»¤¹¬Ê¹"NOR);
                  } else if(exp < 3000000 ){
                        me->set("title", HIR"¶«º£Áú¹¬"HIY"ÎÞµÐ½«¾ü"NOR);
                } else {
                        me->set("title", HIR"¶«º£Áú¹¬"HIY"µ¸º£ÁúÍõ"NOR);
                }

                tell_object(me, "ÁúÅ®¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n");
                tell_room(environment(me),
"ÁúÅ®¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""+me->query("title")+"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{
        command("jump");
	command("say ÎÒÓÖ¶àÁËÒ»¸öµÜ×ÓÒ®£¡\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="¶«º£Áú¹¬")
    {
      message_vision("×ÏÔÆ¹«Ö÷ÄÑ¹ýµØÍû×Å$N£¬ÓûÑÔÓÖÖ¹¡£\n", me);
      return ("ÄãÈ¥ÎÊÎÒ¸¸Íõ°É¡£\n");
    }
  return ("È¥ÎÊÎÊ±ðÈË°É£¡ÎÒÔõÃ´»áÖªµÀ£¡¡\n");
}

void die()
{
	object me,who,longjin;
    string whoid;
    me=this_object();
    if(me->query_temp("longjin_kill"))
	{
		  whoid=me->query_temp("longjin_kill");
    	  if (!present(whoid,environment()))
        	  return ::die();
	  	  who=present(whoid,environment());
          if((who->query("fangcun/panlong_hell_18")=="done")&&(who->query("fangcun/panlong_hell_longjin")=="begin")&&(environment()))
		{
			  longjin=new("/d/sea/obj/longjin");
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
      ::die();
}
ÿ
