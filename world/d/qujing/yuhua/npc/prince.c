// by snowcat 12/8/1997

inherit NPC;

void create()
{
  set_name("ÀÏÍõÒ¯", ({"lao wangye", "wangye", "wang", "ye"}));
  set("title", "Óñ»ªÏØ");
  set("gender", "ÄÐÐÔ");
  set("age", 60);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 100000);
  set("daoxing", 50000);

  set_skill("unarmed", 60);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set("max_gin",600);
  set("max_kee",600);
  set("max_sen",600);
  set("max_force",600);
  set("max_mana",600);
  set("force_factor",50);
  set("eff_dx",10000);
  set("nkgain",50);
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
}

int accept_object(object me, object ob)
  {
        object lw;
        lw=new("/u/mind/lwbook.c");
        
 if((string)ob->query("name")=="ÌìÏÂÃûÆ÷²ÐÆ×" )
        {
         command("smile");
         command("say ÕâÎ»" + RANK_D->query_respect(me) +"ÕæÊÇÓÐÐÄÈË£¬ÎÒ¾ÍÔùÒ»ÀñÎïÓèÄã¡£");
        call_out("destroy", 1, ob);
        lw->move(me);
        
        return 1;       
        }
 }
void destroy(object ob)
{
        destruct(ob);
        return;

}
void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/yuhua") == "done")
    return;
  if (! who->query_temp("obstacle/yuhua_bang"))
    return;
  if (! who->query_temp("obstacle/yuhua_pa"))
    return;
  if (! who->query_temp("obstacle/yuhua_zhang"))
    return;
  if (! who->query_temp("obstacle/yuhua_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/yuhua","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"±ªÍ·É½Ñ°µÃÈý±øÆ÷£¬Öñ½ÚÉ½ÖÆ·þ¾ÅÍ·Ê¨¹Ö£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}
ÿ
