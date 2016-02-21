
inherit NPC;

void create()
{
  set_name("Íõºó", ({"wang hou", "hou", "queen"}));
  set ("long", "ÇÕ·¨¹úÍõºó£¬ÃæÈÝÑÅÀö£¬¾ÙÖ¹¶Ë×¯¡£\n");
  set("title", "ÇÕ·¨¹ú");
  set("gender", "Å®ÐÔ");
  set("age", 30);
  set("combat_exp", 100000);
  set("daoxing", 50000);

  set_skill("blade", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("force", 20);
  set("max_sen", 500);
  set("max_kee", 500);
  set("max_force", 500);
  set("force", 100);
  set("force_factor", 4);

  set("can_sleep",1);
  setup();
 
  carry_object("/d/obj/cloth/gongpao")->wear();
}

void check_hair ()
{
  object me = this_object();

  if (me->query("disable_type") == "<Ë¯ÃÎÖÐ>" &&
      me->query_temp("disabled"))
  {
    call_out("check_hair",1);
    return;
  }

  if (me->query_temp("has_said"))
    return;

  message_vision ("$NÍ»È»ÏÂÒâÊ¶µØÃþÁËÃþÍ·£ºÌìÄÅ£¬ÄÔ´üÈ«Ìê¹âÁË£¡\n",me);
  message_vision ("$NÒ»ÕóÑ£ÔÎ£¬²îµãË¤µ¹ÔÚµØ£¡\n",me);
  me->set_temp("has_said",1);
}
ÿ