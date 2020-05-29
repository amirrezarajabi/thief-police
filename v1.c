// The polices are not moving together
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <windows.h>
int maxim ( int i , int j )
{
    if ( i > j )
    {
        return i ;
    }
    return j ;
}
int minim ( int i , int j )
{
    if ( i > j )
    {
        return j ;
    }
    return i ;
}
int num_of_x_of_map , num_of_y_of_map , num_of_office , num_of_police_office[30] , x_map_of_police[30][200] , y_map_of_police[30][200] ;
int x_robber , y_robber ;
int check_office[30] ;
char map[300][300] , new_map[300][300]  ;
void check_see ( )
{
    int i = 0 , j = 0 ;
    while ( i < num_of_office )
    {
        j = 0 ;
        while ( j < num_of_police_office [i] )
        {
            if ( fabs( x_map_of_police[i][j] - x_robber ) < 3 && fabs( y_map_of_police[i][j] - y_robber ) < 3 )
            {
                check_office[i] = 1 ;
            }
            j = j + 1 ;
        }
        i = i + 1 ;
    }
}
int check_end ( )
{
    int i = 0 , j = 0 ;
    while ( i < num_of_office )
    {
        j = 0 ;
        while ( j < num_of_police_office [i] )
        {
            if (  x_map_of_police[i][j] == x_robber   &&  y_map_of_police[i][j] == y_robber  )
            {
                return 1 ;
            }
            j = j + 1 ;
        }
        i = i + 1 ;
    }
    return 0 ;
}
void random_move_robber ()
{
    int sx = x_robber + rand() % 3  - 1 , sy = y_robber + rand() % 3 - 1 ;
    sx = maxim( 0 , sx ) ;
    sy = maxim( 0 , sy ) ;
    sx = minim( num_of_x_of_map - 1 , sx ) ;
    sy = minim( num_of_y_of_map - 1 , sy ) ;
    map[x_robber][y_robber] = '.' ;
    x_robber = sx ;
    y_robber = sy ;
    map[x_robber][y_robber] = 'R' ;
}
void random_move_police (int i , int j  )
{
    int xx = x_map_of_police[i][j] , yy = y_map_of_police[i][j] ;
    int flag = 0 ;
    int sx , sy ;
    while ( flag == 0 )
    {
        sx = xx + rand() % 3 - 1 ;
        sy = yy + rand() % 3 - 1 ;
        sx = maxim( 0 , sx ) ;
        sy = maxim( 0 , sy ) ;
        sx = minim( num_of_x_of_map - 1 , sx ) ;
        sy = minim( num_of_y_of_map - 1 , sy ) ;
        if ( map[sx][sy] == '.' || map[sx][sy] == 'R')
        {
            char d = map [xx][yy] ;
            map[xx][yy] = '.' ;
            x_map_of_police [i][j] = sx ;
            y_map_of_police [i][j] = sy ;
            map[sx][sy] = d ;
            flag = 1 ;
        }
    }
}
void sleepe ( )
{
    int i = 0 , j = 0 ;
    while ( i < 20000 )
    {
        j = 0 ;
        while ( j < 20000 )
        {
            j = j + 1 ;
        }
        i = i + 1 ;
    }
}
void get_input ( void )
{
    printf( "num of x of map : " ) ;
    scanf ( "%d" , &num_of_x_of_map ) ;
    printf( "num of y of map : " ) ;
    scanf ( "%d" , &num_of_y_of_map ) ;
    printf( "num of office : " ) ;
    scanf ( "%d" , &num_of_office ) ;
    int counter = 0 ;
    while ( counter < num_of_office )
    {
        printf( "num of police of office %d : " , counter + 1 ) ;
        scanf ( "%d" , &num_of_police_office[counter] ) ;
        counter = counter + 1 ;
    }
}
void distribute_map ( void )
{
    int i = 0 , j = 0 , flag = 0 , b[300][300] ;
    x_robber = rand () % num_of_x_of_map ;
    y_robber = rand () % num_of_y_of_map ;
    b[x_robber][y_robber] = 1 ;
    while ( i < num_of_office )
    {
        j = 0 ;
        while ( j < num_of_police_office[i] )
        {
            flag = 0 ;
            while ( flag == 0 )
            {
                x_map_of_police[i][j] = rand () % num_of_x_of_map ;
                y_map_of_police[i][j] = rand () % num_of_y_of_map ;
                if ( b[x_map_of_police[i][j]][y_map_of_police[i][j]] == 0 )
                {
                    flag = 1 ;
                }
            }
            b[x_map_of_police[i][j]][y_map_of_police[i][j]] = 1 ;
            j = j + 1 ;
        }
        i = i + 1 ;
    }
}
void build_map_and_print ( void )
{
    sleepe ( ) ;
    printf("\n\n\n\n\n\n\n");
    //system( "cls" ) ;
    //system( "color 90" ) ;
    int i = 0 , j = 0 ;
    while ( i < num_of_x_of_map )
    {
        j = 0 ;
        while ( j < num_of_y_of_map )
        {
            map [i][j] = '.' ;
            j = j + 1 ;
        }
        i = i + 1 ;
    }
    i = 0 ;
    j = 0 ;
    map [x_robber][y_robber] = 'R' ;
    while ( i < num_of_office )
    {
        j = 0 ;
        while ( j < num_of_police_office [i] )
        {
            map[x_map_of_police[i][j]][y_map_of_police[i][j]] = '1' + i ;
            j = j + 1 ;
        }
        i = i + 1 ;
    }
    i = 0 ;
    j = 0 ;
    while ( i < num_of_x_of_map )
    {
        j = 0 ;
        while ( j < num_of_y_of_map )
        {
            printf ( "%c   " , map[i][j] ) ;
            j = j + 1 ;
        }
        printf( "\n" ) ;
        i = i + 1 ;
    }
    printf( "\n\n") ;
}
void print_map ( void )
{
    printf("\n\n" ) ;
    int i = 0 , j = 0 ;
    while ( i < num_of_x_of_map )
    {
        j = 0 ;
        while ( j < num_of_y_of_map )
        {
            printf ( "%c   " , map[i][j] ) ;
            j = j + 1 ;
        }
        printf( "\n" ) ;
        i = i + 1 ;
    }
}
int smart_move_police ( int i , int j , int x_robber1 , int y_robber1 )
{
    int xx = x_map_of_police[i][j] , yy = y_map_of_police[i][j] ;
    int xxx = x_map_of_police[i][j] , yyy = y_map_of_police[i][j] ;
    if ( xx > x_robber1 )
    {
        xxx = xxx - 1 ;
    }
    if ( xx < x_robber1 )
    {
        xxx = xxx + 1 ;
    }
    if ( yy < y_robber1 )
    {
        yyy = yyy + 1 ;
    }
    if ( yy > y_robber1 )
    {
        yyy = yyy - 1 ;
    }
    if ( map [xxx][yyy] == '.' || map [xxx][yyy] == 'R' )
    {
        char d = map [x_map_of_police[i][j]][y_map_of_police[i][j]] ;
        map [x_map_of_police[i][j]][y_map_of_police[i][j]] = '.' ;
        x_map_of_police[i][j] = xxx ;
        y_map_of_police[i][j] = yyy ;
        map [x_map_of_police[i][j]][y_map_of_police[i][j]] = d ;
        return 0 ;
    }
    if ( map [xx][yyy] == '.' || map [xx][yyy] == 'R' )
    {
        char d = map [x_map_of_police[i][j]][y_map_of_police[i][j]] ;
        map [x_map_of_police[i][j]][y_map_of_police[i][j]] = '.' ;
        x_map_of_police[i][j] = xx ;
        y_map_of_police[i][j] = yyy ;
        map [x_map_of_police[i][j]][y_map_of_police[i][j]] = d ;
        return 0 ;
    }
    if ( map [xxx][yy] == '.' || map [xxx][yy] == 'R' )
    {
        char d = map [x_map_of_police[i][j]][y_map_of_police[i][j]] ;
        map [x_map_of_police[i][j]][y_map_of_police[i][j]] = '.' ;
        x_map_of_police[i][j] = xxx ;
        y_map_of_police[i][j] = yy ;
        map [x_map_of_police[i][j]][y_map_of_police[i][j]] = d ;
        return 0 ;
    }
    return 0 ;
}
int main ( )
{
    int move_robber_counter = 0 , move_police_counter = 0 ;
    srand(time(NULL)) ;
    get_input ( ) ;
    if ( num_of_x_of_map * num_of_y_of_map == 0 )
    {
        printf(":|") ;
        return 0 ;
    }
    distribute_map ( ) ;
    build_map_and_print ( ) ;
    if ( num_of_office == 0 )
    {
        printf(":|") ;
        return 0 ;
    }
    int i = 0, j = 0 , last_x_robber = x_robber ,  last_y_robber = y_robber ;
    while ( check_end() == 0 )
    {
        check_see() ;
        last_x_robber = x_robber ;
        last_y_robber = y_robber ;
        random_move_robber();
        move_robber_counter ++ ;
        if ( check_end() ==

             1 )
        {
            break ;
        }
        i = 0 ;
        j = 0 ;
        while ( i < num_of_office )
        {
            j = 0 ;
            while ( j < num_of_police_office [i] )
            {
                if ( check_office [i] == 0  )
                {
                    random_move_police(i,j) ;
                    move_police_counter ++ ;
                }
                if ( check_office [i] == 1  )
                {
                    smart_move_police(i,j,last_x_robber,last_y_robber) ;
                    move_police_counter ++ ;
                }
                if (check_end()== 1)
                {
                    break ;
                }
                j = j + 1 ;
            }
            i = i + 1 ;
        }
        sleepe();
        sleepe();
        print_map() ;
    }
    sleepe();
    sleepe();
    map[x_robber][y_robber] = 'X' ;
    print_map();
    printf ( "num_of_move_police : %d\n" , move_police_counter ) ;
    printf ( "num_of_move_robber : %d" , move_robber_counter ) ;
    printf("\a");
}
