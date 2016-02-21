// 2001-06-10 By canoe
// 金,木,水,火,土,圣 六种属性

#include <ansi.h>
mapping table=([
	// 金,木,水,火,土,
	"金": ({"木"}),
	"木": ({"水"}),
	"水": ({"火"}),
	"火": ({"土"}),
	"土": ({"金"}),
	]);
string *suss=({
        "\n$N"HIY"身上霞光一闪,$n顿时眼花缭乱。"NOR,
        "\n$N"HIR"身形一晃,属性发挥得淋漓尽致。"NOR,
        "\n$N"HIB"神奇地一颤,$n竟然迷迷糊糊地不知道抵抗。"NOR,
         });
int count(object attacker, object target)
{       
        string att_shuxing,tar_shuxing;// attacker,target的属性
	int result=1;
	att_shuxing=attacker->query("shuxing");
	tar_shuxing=target->query("shuxing");
	if(userp(target)) return 1; // 对player攻击效果不变
       if((random(attacker->query("combat_exp"))<random(target->query("combat_exp")))&&!userp(target))
       // 宠物战斗加经验
       {
       attacker->add("combat_exp",random(50));
       attacker->add("daoxing",random(50));
       }
       //加入圣灵兽 
       if (attacker->query("shuxing")=="圣"&&target->query("shuxing")!="圣")  // attacker 是圣,target不是
         {
              message_vision(suss[random(sizeof(suss))],attacker,target);
              result/=100*(random(150)+150);     // damage * 2.25     
              return result;
         }
       else if (!target->query("shuxing"))
	{
	message_vision(suss[random(sizeof(suss))],attacker,target);
	 return 2*result; // 对npc 效果*2 
        }
     	//对npc攻击力*2,
	else if(member_array(att_shuxing, table[tar_shuxing])>-1)  // target 克制 attacker.
         {
         	message_vision(suss[random(sizeof(suss))],attacker,target);
         	result/=100*(random(100)+100);	// damage * 1.5	
         }	
	else if(member_array(tar_shuxing, table[att_shuxing])>-1) //attacker 克制 target.
	 {
	 	message_vision(suss[random(sizeof(suss))],attacker,target);
	 	result/=100*(random(50)+50);      // damage * 0.75
         }
        return result;
}
