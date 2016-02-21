//camera.c		by Crab, Dec 15, 96

#include <ansi.h>
#include <room.h>
#include <weapon.h>

inherit HAMMER;

#include "desc.h"


void create()
{
/*
	switch(random(20))
	{
		case 0:
		case 16:
		case 17:
		case 18:
		case 19:
			set_name(HIC"傻瓜相机"NOR, ({"papaya camera","camera"}));
			break;
		case 1 :
			set_name(HIC"莱卡Ｒ７"NOR, ({"Leica R7","camera"}));
			break;
		case 2 :
			set_name(HIC"尼康ＦＭ２"NOR, ({"Nikon FM2","camera"}));
			break;
		case 3 :
			set_name(HIC"美能达Ｘ７００"NOR, ({"Minolta X700","camera"}));
			break;
		case 4 :
			set_name(HIC"佳能ＡＬ１"NOR, ({"Canon AL1","camera"}));
			break;
		case 5 :
			set_name(HIC"奥林巴斯ＯＭ４"NOR, ({"Olympus OM4","camera"}));
			break;
		case 6 :
			set_name(HIC"潘太克斯Ｐ３０Ｎ"NOR, ({"Pentax P30N","camera"}));
			break;
		case 7 :
			set_name(HIC"美能达ＸＤ"NOR, ({"Minolta XD", "camera"}));
			break;
		case 8:
			set_name(HIC"尼康Ｆ５"NOR, ({"Nikon F5", "camera"}));
			break;
		case 9 :
			set_name(HIC"莱卡Ｍ１"NOR, ({"Leica M1", "camera"}));
			break;
		case 10 :
			set_name(HIC"尼康Ｆ９０"NOR, ({"Nikon F90", "camera"}));
			break;
		case 11 :
			set_name(HIC"美能达７００Ｓｉ"NOR, ({"Minolta 700Si","camera"}));
			break;
		case 12 :
			set_name(HIC"佳能ＥＯＳ１"NOR, ({"Canon EOS1","camera"}));
			break;
		case 13 :
			set_name(HIC"奥林巴斯ＬＳ１"NOR, ({"Olympus LS1","camera"}));
			break;
		case 14 :
			set_name(HIC"康太克斯ＲＴＳ３"NOR, ({"Contax RTS3","camera"}));
			break;
		case 15 :
			set_name(HIC"美能达９ｘｉ"NOR, ({"Minolta 9xi","camera"}));
			break;
	}
*/
	set_name("摄魂匣", ({"camera"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "架");
		set("value", 100000);
		set("material", "steel");
		set("wield_msg", "$N急急忙忙地举起$n。\n");
		set("unwield_msg", "$N将手中的$n放回包里。\n");
	}
  	init_hammer(10);
	setup();
}

void init()
{
		add_action("do_shoot","shoot");
}


string per_status_msg(int per, string gender)
{                                                                               
	if ( gender == "男性" ) {                                               
    	if ( per>=25 )                                                  
        	return ( per_msg_male1[random(sizeof(per_msg_male1))]); 
		else if ( per>=20 )
        	return ( per_msg_male2[random(sizeof(per_msg_male2))]); 
		else if ( per<20 )
        	return ( per_msg_male3[random(sizeof(per_msg_male3))]); 
    }                                                               
	if ( gender == "女性" ) {
		if ( per>=25 )
        	return ( per_msg_female1[random(sizeof(per_msg_female1))]); 
		else if ( per>=20 )
			return ( per_msg_female2[random(sizeof(per_msg_female2))]);
		else if ( per<20 )
        	return ( per_msg_female3[random(sizeof(per_msg_female3))]);                                                                             
    }                                                               
}                                                                               


int do_shoot(string arg)
{
	object me, obj;
	object pic, env;
	int i;
	mixed *inv;
    mapping exits;
	string objname, objid, str, pro, *dirs;

	me = this_player();

  set("value",0);
  if (me->query("sen")>10)
  {
    me->add("sen",-10);
  }
  else
  {
    me->unconcious();
    return 1;
  }

	if (!arg)
	{
		env = environment(me);
		str = objname = env->query("short");
		if( !env ) str = "照片上灰蒙蒙地一片，不知道是本来就是这样还是冲坏了。\n";
		else
		{
			str = sprintf( "%s的照片\n\n    %s%s\n",env->query("short"), env->query("long"),
					env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

			inv = all_inventory(env);
			for(i=0; i<sizeof(inv); i++) {
				if( inv[i]==me ) continue;
				if ( inv[i]->is_character() )
				{
					if( !me->visible(inv[i]) ) {
					  if(!wizardp(inv[i])) 
					    str += "  " + BLU + inv[i]->name() + NOR;
                                          else continue;
                                        }
					else str += "  " + inv[i]->name();

					str += msg_expression[random(EXP_NUM)] + "\n";
				}
				else str += YEL+"  [ " + inv[i]->name() +" ]\n" +NOR;
			}
		}

		str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
		message_vision("$N轻轻按下了快门…" HIY
				"\n伴随着一道眩目的亮光和咔嚓一声响……\n人脏俱获，铁证如山，跑不掉了！！\n" NOR, me);

		pic=new(__DIR__"photo");
		pic->set_name( objname + "的照片", ({ "photo" }) );
		pic->set("long", str);

		if( !pic->move(me) )
			pic->move(env);

       	return 1;
    }

	if( !objectp(obj = present(arg, environment(me)) ) )
		return notify_fail("你想拍什么？\n");

	if( !(obj -> is_character()) )
		return notify_fail("你想拍谁？\n");

	objname = obj->query("name");
	objid = obj->query("id");
	str = objname+"的照片\n\n";

	switch (random(6))
	{
	case 0:
		str="一张严重曝光过度的照片，好一个“白茫茫一片大地真干净”。\n";
		str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
        break;
	case 1:
		str="一张严重曝光不足的照片，角落里隐隐约约写着“黑夜里乌鸦在飞”。\n";
		str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
        break;
	case 2:
    case 3:
	case 4:
    case 5:
		str += obj->name() + msg_expression[random(EXP_NUM)] + "\n";
		str += obj->long();
	   	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

		if( (string)obj->query("race")=="人类"
		&&	intp(obj->query("age")) )
			str += sprintf("%s看起来约%s多岁。\n", pro, 
			chinese_number( ( ( obj->query("always_young") && (obj->query("age")>obj->query("fake_age")) )?
				obj->query("fake_age"):obj->query("age")) / 10 * 10) );

		str += pro + per_status_msg((int)obj->query("per"), obj->query("gender"));

		inv = all_inventory(obj);
		if( sizeof(inv) ) {
			inv = map_array(inv, "i_look", this_object(), obj->is_corpse()? 0 : 1 );
			inv -= ({ 0 });
			if( sizeof(inv) )
				str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带着：\n%s\n",
					pro, implode(inv, "\n") );
		}
		str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
		break;
    }

	message_vision("$N轻轻按下了快门……"+HIY+"\n伴随着一道眩目的亮光和咔嚓一声响，\n"
			"$n突然觉得身子轻飘飘地，脑袋里空空荡荡，好象魂已经出窍了！\n" NOR,	me, obj);

	pic=new(__DIR__"photo");
	pic->set_name( objname + "的照片", ({ objid+"'s photo", "photo" }) );
	pic->set("long", str);

	if( !pic->move(this_player()) )
		pic->move(environment(this_player()));

	return 1;
}


string i_look(object obj, int flag)
{
	string str;

	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  □" NOR + str;
	else if( !flag )
		str = "    " + str;
	else
		return 0;

	return str;
}
