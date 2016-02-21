// by snowcat 11/22/1997
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("银药盏", ({ "yin yaozhan","yaozhan","zhan"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(5);
  if( clonep() ){
    set_default_object(__FILE__);
  }  else {
    set("unit", "只");
    set("long", "这是一只镂花银药盏。\n");
    set("value", 1000);
  }
}

int is_container()
{
  return 1;
}

void init ()
{
  add_action ("do_fill","fill");  
}

int do_fill (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object horse = present ("horse",where);

  if (! arg)
    return 0;

  if (present(arg, who) != me)
    return 0;

  if (! horse)
    return 0;  

  if (interactive(horse))
    return 0;

  message_vision ("$N将银药盏放在$n的肚皮底下，接了几滴尿汁。\n",who,horse);
  me->set_temp("has_liquid",1);
  return 1;
}

// 0: not valid, 1: valid
int check_valid_drug (object who, object yao, string name)
{
  if (yao->query_temp("is_invalid"))
    return 0;

	if (!who->query_temp("putuo/longear"))
	{
	   if ((name=="大黄" || name=="巴豆" || name=="白芷") &&
         (! yao->query_temp("mixture/"+name)))
          {
            yao->set_temp("mixture/"+name,1);
          }
	else
  {
	
	yao->set_temp("is_invalid",1);
    return 0;
  }
	
	
	}
  if (who->query_temp("putuo/longear")=="左")
	{
	   if ((name=="狗尾草" || name=="牛黄") &&
          (!yao->query_temp("mixture/"+name)))
		{
           yao->set_temp("mixture/"+name,1);
        } 
	    else
  {
	
	yao->set_temp("is_invalid",1);
    return 0;
  }
	
	}
  if (who->query_temp("putuo/longear")=="右")
	{
       if ((name=="紫荆" || name=="陈皮") &&
          (! yao->query_temp("mixture/"+name)))
            {
              yao->set_temp("mixture/"+name,1);
            }
	         else
  {
	
	yao->set_temp("is_invalid",1);
    return 0;
  }
	
	}
  
  
  
  if (yao->query_temp("mixture/大黄") &&
      yao->query_temp("mixture/巴豆") &&
      yao->query_temp("mixture/白芷"))
  {
    yao->set_temp("is_ready",1);
  }
  if (yao->query_temp("mixture/狗尾草") &&
      yao->query_temp("mixture/牛黄")) 
  {
    yao->set_temp("is_longear",1);
  }
  if (yao->query_temp("mixture/紫荆") &&
      yao->query_temp("mixture/陈皮")) 
  {
    yao->set_temp("is_longear",1);
  }
  return 1;
}

void make_drug ()
{
  object me = this_object();
  object who = this_player();
  object yao1 = present("yao 1",me);
  object yao2 = present("yao 2",me);
  string name1, name2;

  if (! yao2)
    return;

  name1 = yao1->query("name");
  name2 = yao2->query("name");
  call_out ("display_message",1,who);
  yao1->set("name","药");
  call_out("destruct_drug",1,yao1);
  if (! me->query_temp("has_liquid"))
  {
    yao2->set_temp("is_invalid",1);
    yao2->set("name","药");
    yao2->set("unit","剂");
	return;
  }
  if (name1=="药")
  {
	yao2->set_temp("is_invalid",1);
    yao2->set("name","药");
    yao2->set("unit","剂");
    return;
  }
  if (name2!="药")
    check_valid_drug (who,yao2,name2);
  check_valid_drug (who,yao2,name1);  
  yao2->set("name","药");
  yao2->set("unit","剂");
}

void display_message (object who)
{
  message_vision ("$N将银药盏里的药混合在一起，搅拌均匀。\n",who);
}

void destruct_drug (object yao)
{
  destruct (yao);
}
