// File      : 
// Purpose   : 
// Created   : 
// By        : Canoe@DHXY-Online

// History   :  Canoe 创建文件


inherit NPC;
inherit F_MASTER;
#include <ansi.h>

  string * cAll =({
                "str","con","cps","cor","spi","per","eff_kee","eff_gin",
                "eff_sen","max_kee","max_gin","max_sen","mana_factor",
                "force_factor","combat_exp","daoxing",
                  });

mapping mpWhere = ([
                "长安":"/d/city",
                "龙宫":"/d/sea",
                "傲来国":"/d/dntg/hgs", 
                "普陀山":"/d/nanhai",
                "五庄观":"/d/qujing/wuzhuang",  
                "豹头山":"/d/qujing/baotou",
                "宝象国":"/d/qujing/baoxiang",
                "碧波潭":"/d/qujing/bibotan",
                "比丘国":"/d/qujing/biqiu",
                "车迟国":"/d/qujing/chechi",
                "毒敌山":"/d/qujing/dudi",
                "凤仙郡":"/d/qujing/fengxian",
                "火焰山":"/d/qujing/firemount",
                /*
                .
                .
                .
                */
                 ]);

string team_guai(object * oTarget)
{
        int i , iSize ;
        string cName , cTid , cMid ;
        object oLeader , oMe ;
                
        iSize = sizeof( oTarget );
        oLeader = oTarget[0];
        cName = oLeader->query("name");
        oLeader->set("leader",1);
        cMid = oLeader->query("id");
        
        for ( i = 1 ; i< iSize ; i ++ )
        {       
                oMe = oTarget[i] ;
                cTid = oMe->query("id") ;
                "/cmds/std/team"->main(oLeader , "with " + cTid);
                "/cmds/std/team"->main( oMe , "with " + cTid );
                "/cmds/std/follow"->main( oMe , cMid );
                         oMe->set_temp("guardfor" , cMid );
                cName = sprintf ("%s、%s" , cName , oTarget->query("name") );
        }
        return cName ;
}

int max_skill(object oOb)
{
                 int *iSkill , iMax , i ;
        mapping mSkill = oOb->query_skills();

        i = sizeof( mSkill );
        
        if( i )
        {
                iSkill = values( mSkill );
                iMax = iSkill[0] ;
                
                while(i--)
                {
                        if ( iSkill[i] > iMax )
                                 iMax = iSkill[i];
                }
         }
         
                else 
                               iMax = 200 ;
         return iMax ;
}
void set_dragon( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("fork", iSkill);
        oGuai->set_skill("fengbo-cha", iSkill);
        oGuai->set_skill("hammer",iSkill);
        oGuai->set_skill("huntian-hammer",iSkill);
        oGuai->set_skill("dragonstep", iSkill);
        oGuai->set_skill("dragonfight", iSkill);
        oGuai->set_skill("dragonforce", iSkill);
        oGuai->set_skill("seashentong", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "dragonforce");
        oGuai->map_skill("fork", "fengbo-cha");
        oGuai->map_skill("hammer","huntian-hammer");
        oGuai->map_skill("parry", "huntian-hammer");
        oGuai->map_skill("spells", "seashentong");
        oGuai->map_skill("dodge", "dragonstep");
        oGuai->map_skill("unarmed", "dragonfight");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("东海龙宫",2 , "水族");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"hammer", "break" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/hammer/hammer.c")->wield();
}

void set_fc ( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("sword", iSkill);
        oGuai->set_skill("liangyi-sword", iSkill);
        oGuai->set_skill("stick",iSkill);
        oGuai->set_skill("qianjun-bang",iSkill);
        oGuai->set_skill("jindouyun", iSkill);
        oGuai->set_skill("puti-zhi", iSkill);
        oGuai->set_skill("wuxiangforce", iSkill);
        oGuai->set_skill("dao", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "wuxiangforce");
        oGuai->map_skill("sword", "liangyi-sword");
        oGuai->map_skill("stick","qianjun-bang");
        oGuai->map_skill("parry", "qianjun-bang");
        oGuai->map_skill("spells", "dao");
        oGuai->map_skill("dodge", "jindouyun");
        oGuai->map_skill("unarmed", "puti-zhi");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("方寸山三星洞",2 , "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"stick", "qiankun" :),
                                        (: perform_action,"stick", "pili" :),
                                        (: perform_action,"stick", "leiting" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/stick/mugun.c")->wield();
}

void set_hell( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("sword", iSkill);
        oGuai->set_skill("zhuihun-sword", iSkill);
        oGuai->set_skill("stick",iSkill);
        oGuai->set_skill("kusang-bang",iSkill);
        oGuai->set_skill("whip",iSkill);
        oGuai->set_skill("hellfire-whip",iSkill);
        oGuai->set_skill("ghost-steps", iSkill);
        oGuai->set_skill("jinghun-zhang", iSkill);
        oGuai->set_skill("tonsillit", iSkill);
        oGuai->set_skill("gouhunshu", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "tonsillit");
        oGuai->map_skill("sword", "zhuihun-sword");
        oGuai->map_skill("stick","kusang-bang");
        oGuai->map_skill("whip","hellfire-whip");
        oGuai->map_skill("parry", "hellfire-whip");
        oGuai->map_skill("spells", "gouhunshu");
        oGuai->map_skill("dodge", "ghost-steps");
        oGuai->map_skill("unarmed", "jinghun-zhang");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("阎罗地府",2 , "你好");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"whip", "three" :),
                                        (: perform_action,"whip", "ldlh" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/whip/tielian.c")->wield();
}

void set_hyd( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("spear", iSkill);
        oGuai->set_skill("wuyue-spear", iSkill);
        oGuai->set_skill("huoyun-qiang", iSkill);
        oGuai->set_skill("stick",iSkill);
        oGuai->set_skill("dali-bang",iSkill);
        oGuai->set_skill("fork",iSkill);
        oGuai->set_skill("yueya-chan",iSkill);
        oGuai->set_skill("moshenbu", iSkill);
        oGuai->set_skill("moyun-shou", iSkill);
        oGuai->set_skill("huomoforce", iSkill);
        oGuai->set_skill("pingtian-dafa", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "huomoforce");
        oGuai->map_skill("spear", "huoyun-qiang");
        oGuai->map_skill("stick","dali-bang");
        oGuai->map_skill("fork","yueya-chan");
        oGuai->map_skill("parry", "huoyun-qiang");
        oGuai->map_skill("spells", "pingtian-dafa");
        oGuai->map_skill("dodge", "moshenbu");
        oGuai->map_skill("unarmed", "moyun-shou");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("火云洞", 2, "蓝");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"spear", "ji" :),
                                        (: perform_action,"spear", "lihuo" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/spear/changqiang.c")->wield();
}

void set_moon( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("whip", iSkill);
        oGuai->set_skill("jueqingbian", iSkill);
        oGuai->set_skill("sword",iSkill);
        oGuai->set_skill("snowsword",iSkill);
        oGuai->set_skill("blade",iSkill);
        oGuai->set_skill("xuanhu-blade",iSkill);
        oGuai->set_skill("moondance", iSkill);
        oGuai->set_skill("baihua-zhang", iSkill);
        oGuai->set_skill("moonforce", iSkill);
        oGuai->set_skill("moonshentong", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "moonforce");
        oGuai->map_skill("sword", "snowsword");
        oGuai->map_skill("whip","queqingbian");
        oGuai->map_skill("blade","xuanhu-blade");
        oGuai->map_skill("parry", "snowsword");
        oGuai->map_skill("spells", "moonshentong");
        oGuai->map_skill("dodge", "moondance");
        oGuai->map_skill("unarmed", "baihua-zhang");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("月宫", 2, "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"sword", "hudie" :),
                                        (: perform_action,"sword", "tian" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/sword/changjian.c")->wield();
}

void set_psd( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("whip", iSkill);
        oGuai->set_skill("yinsuo-jinling", iSkill);
        oGuai->set_skill("sword",iSkill);
        oGuai->set_skill("qingxia-jian",iSkill);
        oGuai->set_skill("chixin-jian",iSkill);
        oGuai->set_skill("qin",iSkill);
        oGuai->set_skill("yueying-wubu", iSkill);
        oGuai->set_skill("lanhua-shou", iSkill);
        oGuai->set_skill("jiuyin-xinjing", iSkill);
        oGuai->set_skill("pansi-dafa", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "jiuyin-xinjing");
        oGuai->map_skill("sword", "chixin-jian");
        oGuai->map_skill("whip","yinsuo-jinling");
        oGuai->map_skill("parry", "yinsuo-jinling");
        oGuai->map_skill("spells", "pansi-dafa");
        oGuai->map_skill("dodge", "yueying-wubu");
        oGuai->map_skill("unarmed", "lanhua-shou");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("盘丝洞", 2, "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"whip", "wang" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/whip/wuchou.c")->wield();
}

void set_pt( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("staff", iSkill);
        oGuai->set_skill("lunhui-zhang", iSkill);
        oGuai->set_skill("spear",iSkill);
        oGuai->set_skill("huoyun-qiang",iSkill);
        oGuai->set_skill("lotusmove", iSkill);
        oGuai->set_skill("jienan-zhi", iSkill);
        oGuai->set_skill("lotusforce", iSkill);
        oGuai->set_skill("buddhism", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "lotusforce");
        oGuai->map_skill("staff", "lunhui-zhang");
        oGuai->map_skill("spear","huoyun-qiang");
        oGuai->map_skill("parry", "lunhui-zhang");
        oGuai->map_skill("spells", "buddhism");
        oGuai->map_skill("dodge", "lotusmove");
        oGuai->map_skill("unarmed", "jienan-zhi");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("南海普陀山", 2, "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"staff", "pudu" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/staff/chanzhang.c")->wield();
        oGuai->carry_object("d/obj/weapon/staff/chanzhang.c")->wield();
}

void set_ss ( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("sword", iSkill);
        oGuai->set_skill("yujianshu", iSkill);
        oGuai->set_skill("mindsword", iSkill);
        oGuai->set_skill("canxin-jian",iSkill);
        oGuai->set_skill("whip", iSkill);
        oGuai->set_skill("yirubian",iSkill);
        oGuai->set_skill("sevensteps", iSkill);
        oGuai->set_skill("hunyuan-zhang", iSkill);
        oGuai->set_skill("fumozhang", iSkill);
        oGuai->set_skill("zixia-shengong", iSkill);
        oGuai->set_skill("taoism", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "zixia-shengong");
        oGuai->map_skill("sword", "mindsword");
        oGuai->map_skill("whip","yirubian");
        oGuai->map_skill("parry", "mindsword");
        oGuai->map_skill("spells", "taoism");
        oGuai->map_skill("dodge", "sevensteps");
        oGuai->map_skill("unarmed", "hunyuan-zhang");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("蜀山剑派", 5, "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"sword", "taohua" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/sword/changjian.c")->wield();
}

void set_wdd ( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("sword", iSkill);
        oGuai->set_skill("qixiu-jian", iSkill);
        oGuai->set_skill("blade", iSkill);
        oGuai->set_skill("kugu-blade",iSkill);
        oGuai->set_skill("lingfu-steps", iSkill);
        oGuai->set_skill("yinfeng-zhua", iSkill);
        oGuai->set_skill("huntian-qigong", iSkill);
        oGuai->set_skill("yaofa", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "huntian-qigong");
        oGuai->map_skill("sword", "qixiu-jian");
        oGuai->map_skill("blade","kugu-blade");
        oGuai->map_skill("parry", "kugu-blade");
        oGuai->map_skill("spells", "yaofa");
        oGuai->map_skill("dodge", "lingfu-steps");
        oGuai->map_skill("unarmed", "yinfeng-zhua");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("陷空山无底洞", 2, "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"blade", "diyu" :),
                                        (: perform_action,"blade", "pozhan" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/blade/blade.c")->wield();
}

void set_wzg( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("hammer", iSkill);
        oGuai->set_skill("kaishan-chui", iSkill);
        oGuai->set_skill("blade", iSkill);
        oGuai->set_skill("yange-blade",iSkill);
        oGuai->set_skill("staff", iSkill);
        oGuai->set_skill("fumo-zhang", iSkill);
        oGuai->set_skill("sword", iSkill);
        oGuai->set_skill("sanqing-jian", iSkill);
        oGuai->set_skill("xiaofeng-sword", iSkill);
        oGuai->set_skill("zouxiao", iSkill);
        oGuai->set_skill("baguazhen", iSkill);
        oGuai->set_skill("wuxing-quan", iSkill);
        oGuai->set_skill("zhenyuan-force", iSkill);
        oGuai->set_skill("taiyi", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "zhenyuan-force");
        oGuai->map_skill("sword", "sanqing-jian");
        oGuai->map_skill("blade","yange-blade");
        oGuai->map_skill("staff","fumo-zhang");
        oGuai->map_skill("hammer","kaishan-chui");
        oGuai->map_skill("parry", "sanqing-jian");
        oGuai->map_skill("spells", "taiyi");
        oGuai->map_skill("dodge", "baguazhen");
        oGuai->map_skill("unarmed", "wuxing-quan");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("五庄观", 2, "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"sword", "sanqing" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/sword/changjian.c")->wield();
}

void set_xs ( object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("unarmed", iSkill);
        oGuai->set_skill("dodge", iSkill);
        oGuai->set_skill("parry", iSkill);
        oGuai->set_skill("force", iSkill);
        oGuai->set_skill("spells", iSkill);
        oGuai->set_skill("blade", iSkill);
        oGuai->set_skill("bingpo-blade",iSkill);
        oGuai->set_skill("sword", iSkill);
        oGuai->set_skill("bainiao-jian", iSkill);
        oGuai->set_skill("throwing", iSkill);
        oGuai->set_skill("xiaoyaoyou", iSkill);
        oGuai->set_skill("cuixin-zhang", iSkill);
        oGuai->set_skill("ningxie-force", iSkill);
        oGuai->set_skill("dengxian-dafa", iSkill);
        oGuai->set_skill("literate", 180 );
        oGuai->map_skill("force", "ningxie-force");
        oGuai->map_skill("sword", "bainiao-jian");
        oGuai->map_skill("blade","bingpo-blade");
        oGuai->map_skill("throwing","bainiao-jian");
        oGuai->map_skill("parry", "bainiao-jian");
        oGuai->map_skill("spells", "dengxian-dafa");
        oGuai->map_skill("dodge", "xiaoyaoyou");
        oGuai->map_skill("unarmed", "cuixin-zhang");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("大雪山", 2, "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"blade", "xuan" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("d/obj/weapon/blade/iceblade.c")->wield();
}

void set_jjf(object oGuai , int iSkill )
{
        iSkill += random( iSkill / 4 );
        
        oGuai->set_skill("changquan", iSkill );
        oGuai->set_skill("yanxing-steps", iSkill );
        oGuai->set_skill("spear", iSkill );
        oGuai->set_skill("mace", iSkill );
        oGuai->set_skill("axe", iSkill );
        oGuai->set_skill("force", iSkill );
        oGuai->set_skill("unarmed", iSkill );
        oGuai->set_skill("dodge", iSkill );
        oGuai->set_skill("parry", iSkill );
        oGuai->set_skill("spells", iSkill );
        oGuai->set_skill("xuanyuan-archery", iSkill );
        oGuai->set_skill("jinglei-mace", iSkill );
        oGuai->set_skill("sanban-axe", iSkill );
        oGuai->set_skill("archery", iSkill );
        oGuai->set_skill("bawang-qiang", iSkill );
        oGuai->set_skill("lengquan-force", iSkill );
        oGuai->set_skill("literate", 180 );
        oGuai->set_skill("baguazhou", iSkill + 20 );
        oGuai->map_skill("spells", "baguazhou");
        oGuai->map_skill("force", "lengquan-force");
        oGuai->map_skill("unarmed", "changquan");
        oGuai->map_skill("spear", "bawang-qiang");
        oGuai->map_skill("parry", "jinglei-mace");
        oGuai->map_skill("mace", "jinglei-mace");
        oGuai->map_skill("archery", "xuanyuan-archery");
        oGuai->map_skill("axe", "sanban-axe");
        oGuai->map_skill("dodge", "yanxing-steps");
        oGuai->set("force_factor", oGuai->query_skill("force")/2);
        oGuai->set("mana_factor", oGuai->query_skill("spells",1));
        oGuai->create_family("将军府",2 , "弟子");
        // oGuai->set("title",RED"浑然天成"NOR);
        oGuai->set("chat_chance_combat", 40);
        oGuai->set("chat_msg_combat", ({
                                        (: perform_action,"axe", "sanban" :),
                                     }) );                
        oGuai->carry_object("/d/obj/armor/jinjia.c")->wear();
        oGuai->carry_object("/d/obj/weapon/axe/huafu.c")->wield();
}
void set_npc_status(object oMe , object oGuai , int iSkill)
{
        int i , iMax , iRatio ;
        mapping mpStatus ;
        
        iRatio = 1 ; // 临时
        iSkill *= iRatio ;
        iMax = sizeof( cAll );
        
        switch ( random(12) )
        {
                case 0 : set_dragon( oGuai , iSkill );
                         break ;
                case 1 : set_jjf( oGuai , iSkill );
                         break ;
                case 2 : set_fc( oGuai , iSkill );
                         break ;
                case 3 : set_hell( oGuai , iSkill );
                         break ;
                case 4 : set_hyd( oGuai , iSkill );
                         break ;
                case 5 : set_moon( oGuai , iSkill );
                         break ;
                case 6 : set_psd( oGuai , iSkill );
                         break ;
                case 7 : set_pt( oGuai , iSkill );
                         break ;
                case 8 : set_ss( oGuai , iSkill );
                         break ;
                case 9 : set_wdd( oGuai , iSkill );
                         break ;
                case 10 : set_wzg( oGuai , iSkill );
                         break ;
                default : set_xs( oGuai , iSkill );
                         break ;         
        }
        // set hp
        mpStatus = oMe->query_entire_dbase();
        for ( i = 0 ; i < iMax ; i ++ )
                oGuai->set( cAll[i] , mpStatus[cAll[i]]*iRatio );
        
}

string * random_place()
{
        int  i, j, k;
        object oRoom;
        mixed * file, exit ;
        string cTemp ,sDir , cWhere ,* cKey ;
        
        cKey = keys( mpWhere );
        i = random( sizeof(cKey) );
        cTemp = cKey[i];
        cWhere = cTemp ;
        sDir = mpWhere[cTemp];
        file = get_dir( sDir +"/*.c", -1 );
        if ( !sizeof(file) )
                return ({"",""});
        for( k = 0 ; k < 10 ; k ++ )
        {
                j = random(sizeof(file));
                
                if ( file[j][1] > 0 )
                {
                        cTemp = sDir+"/"+file[j][0] ;
                        oRoom=load_object(cTemp);
                        if (oRoom)
                        {  
                                if ( oRoom->query("no_fight") ||
                                     oRoom->query("no_magic") ||
                                     oRoom->query("no_mieyao") ||
                                     !(exit=oRoom->query("exits")) ||
                                     sizeof(exit)<1 ||
                                     !oRoom->query("outdoors") )
                                        continue;
                                return ({cWhere,cTemp}); ;
                         }
                }
         }
         return ({"",""});
}

string give_task()
{
        int i , iTemp , iTime , iMax , iMin , j , k  , iSize ;
        string * sWhere , cName , sStr , sDir ;
        object * oTeam ;
        object oMe = this_player();
        object oOb = this_object();
        object oTemp , oGuai , * oTarget ;
           
        if ( !pointerp( oTeam = oMe->query_team()) )
                return "你现在并没有参加任何队伍。\n";
           
        if ( !oMe->is_team_leader() )
                return "还是让队长来吧。\n";
           
        if ( (iSize = sizeof(oTeam) ) > 3 )
                return "队伍不要太大吧？3个最多了。\n";
        
        iTime = time() ;

        for ( k = 0 ; k < iSize ; k ++ )        
        {
                oTemp = oTeam[k] ;
                if ( iTime - oTemp->query("tk/time") < 10*60  )
                        iTemp ++ ;
                
                if ( environment(oMe) != environment(oTemp) )
                        i ++ ;

                if ( !iMax )
                        iMax = oTemp->query("combat_exp");
                if ( !iMin )
                        iMin = oTemp->query("combat_exp");
                j = oTemp->query("combat_exp");
                if ( j > iMax )
                        iMax = j ;
                else if ( iMin > j )
                        iMin = j ;
        }
        if ( iTemp )
                return "队伍中有人上次接了任务没有完成。\n" ;
        if ( i )
                return "队员都到齐了？\n" ;
        if ( iMin < 1000000 )
                return "你队伍中有人经验不适合做这么危险的任务。\n" ;
        if ( iMin + iMin < iMax )
                return "你队伍中经验相差太悬殊。\n" ;
        
       for ( k = 0 ; k < iSize ; k ++ ) 
        {
                oTemp = oTeam[k] ;
                if ( !iMax )
                        iMax = max_skill( oTemp );
                iMin =  max_skill( oTemp );
                if ( iMin > iMax )
                        iMax = iMin ;
        }
        
        sWhere = random_place();
        sDir = sWhere[1];
        sStr = sWhere[0];
        
        if ( strlen(sStr) < 2 )
                return "出错了，通知wiz。\n";
                
        i = i + random(3);
        for ( j = 0 ; j<i ; j++ )
        { 
                  oGuai = new ("/u/canoe/guai.c");  
                
                if ( !oGuai )
                        return "创建怪物失败";
                
                set_npc_status( oMe , oGuai , iMax );
        
                oGuai->set("teamkill" , oTeam );
                if ( wizardp(oMe) )
                        tell_object(oMe , sprintf("妖怪在%s", sDir ) );
                oGuai->move( sDir );
                
                if ( !sizeof(oTarget) )
                        oTarget = ({ oGuai });
                else 
                        oTarget += ({ oGuai });
        } 
     
        cName = team_guai( oTarget );     
        
        for ( k = 0 ; k < iSize ; k ++ )        
        {
                oTemp = oTeam[k] ;
                oTemp->set("tk/info" , sprintf("%s的%s。",sStr,cName) );
                oTemp->set("tk/target" , oTarget );
                oTemp->set("tk/time" ,iTime );
        }
        return sprintf("听说%s在%s为非作歹，你们速去降服！" , cName , sWhere[0] );
}

void create()
{
   set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "救苦救难大慈大悲");
   set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
   set("gender", "女性");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("rank_info/respect", "菩萨娘娘");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("daoxing", 50000000);
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 150);
   set_skill("jienan-zhi", 150);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 150);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 150);
   set_skill("lunhui-zhang", 180);
   set_skill("spear", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("inquiry", ([
        "任务": (: give_task :),
        "job": (: give_task :),
      ]));
   
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
   }) );
   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("南海普陀山", 1, "菩萨");

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}
