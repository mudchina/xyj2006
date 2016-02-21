//¸ºÔð´æ·Å¸÷ÃÅÅÉÖ®¼äµÄ¡°ÓÑºÃ¶È¡±¡£
//Qyz
#include <ansi.h>

inherit F_SAVE;

#define FAMILY_ENEMY    2
#define FAMILY_FRIEND   1

mapping ALL_FAMILYS=(["·½´çÉ½ÈýÐÇ¶´":1,
                 "ÄÏº£ÆÕÍÓÉ½":1,
                 "Îå×¯¹Û":1,
                 "ÑÖÂÞµØ¸®":-1,
                 "ÔÂ¹¬":1,
                 "¶«º£Áú¹¬":1,
                 "´óÑ©É½":-1,
                 "ÏÝ¿ÕÉ½ÎÞµ×¶´":-1,
                 "ÅÌË¿¶´":-1,
                 "½«¾ü¸®":1,
                 "Èý½çÉ¢ÏÉ":-1,
                 "À¥ÂØÉ½ÓñÐé¶´":1,
                 "»ðÔÆ¶´":-1,
                 "ÊñÉ½ÅÉ":1,
                
]);

mapping MASTERS=(["·½´çÉ½ÈýÐÇ¶´":"ÆÐÌáÀÏ×æ",
                 "ÄÏº£ÆÕÍÓÉ½":"¹ÛÒôÆÐÈø",
                 "Îå×¯¹Û":"ÕòÔª´óÏÉ",
                 "ÑÖÂÞµØ¸®":"ÑÖÂÞÍõ",
                 "ÔÂ¹¬":"æÏ¶ð",
                 "¶«º£Áú¹¬":"°Á¹ã",
                 "´óÑ©É½":"´óÅôÃ÷Íõ",
                 "ÏÝ¿ÕÉ½ÎÞµ×¶´":"ÓñÊó¾«",
                 "ÅÌË¿¶´":"×ÏÏ¼ÏÉ×Ó",
                 "½«¾ü¸®":"°×·¢ÀÏÈË",
                 "Èý½çÉ¢ÏÉ":"ÖÐÉ½·ò×Ó",
                 "À¥ÂØÉ½ÓñÐé¶´":"½ª×ÓÑÀ",
                 "»ðÔÆ¶´":"ºìº¢¶ù",
                 "ÊñÉ½ÅÉ":"ÀîåÐÒ£",
]);

mapping family;

void create()
{
    seteuid(getuid());
    if ( !restore() && !mapp(family) ){
        family = ([]);
    }
}

int remove()
{
    save();
    return 1;
}

int family_relation(string your_fam,string my_fam )
{
        return ALL_FAMILYS[your_fam]*ALL_FAMILYS[my_fam];
}

string query_save_file() { return DATA_DIR + "familyd"; }

int set_relation(string my_fam, mapping relation)
{
    family[my_fam] = relation;
    save();
    return 1;
}

int add_family_enemy( string my_fam, string name, int score )
{
    if( undefinedp( family[my_fam] ) )
        family[my_fam] = ([ name : score ]);
    if( !undefinedp(family[my_fam][name] ) )
        family[my_fam][name] += score;
    else family[my_fam] += ([ name : score ]);
    save();
    return 1;
}

int remove_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] ) ) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
    {
        map_delete(family[my_fam] , name);
        save();
            return 1;
    }
    else return 0;
}

int is_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name])&&family[my_fam][name]>100)
        return 1;
    else return 0;
}

int query_enemy_quantity( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
        return family[my_fam][name];
    else return 0;
}
        
mapping query_relation(string my_fam)
{
    if ( !undefinedp(family[my_fam]) )
        return family[my_fam];
    else
        return ([]);
}

int deal_family_relation( object victim, object killer )
{
    mapping my_family, your_family;
    int c_score, y_relation, m_relation; 
    string my_fam, your_fam, my_id, your_id, declare;

    string* sname;
    int i;

    your_id = killer->query("id");
    if( your_family = killer->query("family") )
    {
        your_fam = your_family["family_name"];
        my_id = victim->query("id");    
        if( !undefinedp(family[your_fam]) &&
        !undefinedp(family[your_fam][my_id]) )
        {
            killer->add("faith" , family[your_fam][my_id]/100 );
            {
                declare = sprintf("[1;37m×ÝÉù³¤Ð¥:[33m%s[1;37mÉ±ËÀ±¾ÃÅ³ðµÐ[32m%s[1;37m£¬ÕæÄË´ó¿ìÈËÐÄ¡£\n",
                                killer->name(1), victim->name(1) );
                message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());
            }
            map_delete(family[your_fam] , my_id );
            return 1;
        }

        if( my_family = victim->query("family") )
        {
            my_fam = my_family["family_name"];
            c_score = victim->query("faith");
            if( my_fam == your_fam )
            {
                killer->add("faith", -( c_score/100 + 1 ) );
                if(c_score > 30 )  
                {
                    declare = sprintf("[1;37m×ÝÉù³¤Ð¥:[32m%s[1;37m²»¿ÉÔÙÍÀÂ¾±¾ÃÅÊ¦ÐÖµÜ£¬ÇÐ²»¿ÉÍ¬ÃÅÏà²Ð£¡¡£\n", killer->name(1) );
                    message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());                    
                }     
                return 1;                                             
            }
            else
            {    
                if( userp( killer ) )
                    add_family_enemy( my_fam, your_id, c_score );
                if( y_relation = family_relation( your_fam, my_fam ) )
                {                                           
                    if( y_relation == FAMILY_ENEMY )
                    {
                        killer->add("faith" , c_score/100 );
                        killer->add("relation/"+my_fam,c_score/100);
                        sname=keys(ALL_FAMILYS);
                        if(c_score > 30 )
                        {
                            declare = sprintf("[1;37m×ÝÉù³¤Ð¥:[32m%s[1;37m³ÔµôÁË±¾ÃÅ¶ÔÍ·[33m%s[1;37mµÄ[35m%s£¬[1;37m¹¦µÂÎÞÁ¿Ò²£¡\n",
                                    killer->name(1), my_fam, victim->name(1) );
                            message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());                            
                        }
                    }
                    else if( y_relation == FAMILY_FRIEND )
                    {
                        killer->add("faith" , -c_score/100 );
                        killer->add("relation/"+my_fam,-c_score/100);       
                        if(c_score > 30 )
                        {
                            declare = sprintf("[1;37m×ÝÉù³¤Ð¥:±¾ÃÅµÜ×ÓÓ¦¸ÃÓë[33m%s[1;37mµÄµÜ×ÓºÍÄÀÏà´¦£¬²»Ó¦»¥ÏàÉ±Â¾¡£\n",
                                        my_fam );
                            message("channel:chat",HIR+MASTERS[your_fam]+declare+NOR,users());
                        }
                    }
                }
                if( m_relation = family_relation( my_fam, your_fam ))
                {
                    if( m_relation == FAMILY_ENEMY )
                    declare = sprintf("[1;37m×ÝÉù³¤Ð¥:±¾ÃÅÓë[32m%s[mÊÆ²»Á½Á¢£¬µÜ×ÓÃÇÒªÇÐ¼Ç³ðºÞ°¡£¡\n",
                                        your_fam );
                    else
                    declare = sprintf("[1;37m×ÝÉù³¤Ð¥:±¾ÃÅ[31m%s[1;37m±»[33m%s[1;37mµÄ[32m%s[1;37m³ÔµôÁË£¬Í¬ÃÅµÜ×Ó½ÔÓ¦ÒÔ±¨³ðÎª¼ºÈÎ£¡\n",
                                    victim->name(1), your_fam, killer->name(1) );
           
                    message("channel:chat",HIR+MASTERS[my_fam]+declare+NOR,users());
                }
                return 1;                                              
            }             
        }
        else return 0;
    }
    else if( my_family = victim->query("family") )                   
    {
        my_fam = my_family["family_name"];
        c_score = victim->query("faith");
        if( userp(killer) )
            add_family_enemy( my_fam, your_id, c_score );
       killer->add("relation/"+my_fam,c_score/100);
        {
            declare = sprintf("[1;37m×ÝÉù³¤Ð¥:±¾ÃÅµÜ×Ó±»[32m%s[1;37mÉ±º¦ÁË¡£\n", killer->name(1) );
            message("channel:chat",HIR+MASTERS[my_fam]+declare+NOR,users());
        }
        return 1;
    }
    else return 0;
}

void clear_all_family_relation( string id )
{
    int i;
    string *familys = keys(ALL_FAMILYS);
    for( i = 0; i<sizeof(familys); i++ )
    {
        if( undefinedp( family[familys[i]] ) ||
            undefinedp( family[familys[i]][id] ) )
        continue;
        map_delete( family[familys[i]], id );
    }
}
