#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50  // 식당 이름의 최대 길이
#define INIT_CAPACITY 10 // 동적 배열의 초기 용량

// 음식 종류를 나타내는 열거형
typedef enum { Korean, Chinese, Japanese, Western, Unknown } FoodType;

// 식당 정보를 저장하는 구조체
typedef struct {
  char name[MAX_NAME_LEN]; // 식당 이름
  FoodType type;           // 음식 종류 (Korean, Chinese, Japanese, Western)
  double x;                // 식당의 x 좌표
  double y;                // 식당의 y 좌표
  double score;            // 평점 (0.0 ~ 5.0)
} Restaurant;

// 식당 정보들을 관리하는 구조체
typedef struct {
  Restaurant *restaurants; // 식당 정보를 저장하는 동적 배열
  int capacity;            // 동적 배열의 현재 용량
  int count;               // 저장된 식당 개수
} RestaurantManager;

// 함수 선언
void add_restaurant(RestaurantManager *manager);
void recommend_restaurants(RestaurantManager *manager);
void search_restaurants(RestaurantManager *manager);
void print_restaurant(Restaurant restaurant);
void reallocate_restaurants(RestaurantManager *manager);
double calculate_distance(double x1, double y1, double x2, double y2);
FoodType get_food_type(const char *type_str);
void print_food_type(FoodType type);

// 식당 정보를 추가하는 함수
void add_restaurant(RestaurantManager *manager) {
  if (manager->count >= manager->capacity) {
    reallocate_restaurants(manager);
  }

  printf("--- Add Restaurant ---\n");

  // 식당 이름 입력
  printf("Enter restaurant name: ");
  scanf("%s", manager->restaurants[manager->count].name);

  // 음식 종류 입력
  char type_str[20];
  printf("Enter food type (Korean, Chinese, Japanese, Western): ");
  scanf("%s", type_str);

  manager->restaurants[manager->count].type = get_food_type(type_str);
  if (manager->restaurants[manager->count].type == Unknown) {
    printf("Invalid food type.\n");
    getchar(); // 남아 있는 개행 문자 제거
    return;
  }

  // 위치 입력
  printf("Enter location (x y): ");
  if (scanf("%lf %lf", &manager->restaurants[manager->count].x, &manager->restaurants[manager->count].y) != 2) {
    printf("Invalid location format.\n");
    getchar(); // 남아 있는 개행 문자 제거
    return;
  }

  // 평점 입력
  printf("Enter score (0.0 ~ 5.0): ");
  if (scanf("%lf", &manager->restaurants[manager->count].score) != 1 ||
      manager->restaurants[manager->count].score < 0.0 ||
      manager->restaurants[manager->count].score > 5.0) {
    printf("Invalid score.\n");
    getchar(); // 남아 있는 개행 문자 제거
    return;
  }

  manager->count++;
  printf("Restaurant added successfully!\n");
  getchar(); // 남아 있는 개행 문자 제거
}

// 추천 식당 출력 함수
void recommend_restaurants(RestaurantManager *manager) {
  char type_str[20];
  double x, y, min_score;

  printf("--- Recommend Restaurants ---\n");
  printf("Enter food type (Korean, Chinese, Japanese, Western): ");
  scanf("%s", type_str);

  FoodType type = get_food_type(type_str);
  if (type == Unknown) {
    printf("Invalid food type.\n");
    return;
  }

  printf("Enter your location (x y): ");
  scanf("%lf %lf", &x, &y);
  printf("Enter minimum score: ");
  scanf("%lf", &min_score);

  printf("\n--- Recommended Restaurants ---\n");
  int found = 0;

  for (int i = 0; i < manager->count; i++) {
    if (manager->restaurants[i].type == type &&
        calculate_distance(x, y, manager->restaurants[i].x, manager->restaurants[i].y) <= 500 &&
        manager->restaurants[i].score >= min_score) {
      print_restaurant(manager->restaurants[i]);
      found = 1;
    }
  }

  if (!found) {
    printf("No result\n");
  }
}

// 검색 식당 출력 함수
void search_restaurants(RestaurantManager *manager) {
  char query[MAX_NAME_LEN];
  double x, y, distance;

  printf("--- Search for Restaurants ---\n");
  printf("Enter search query (type, name, or location): ");
  fgets(query, MAX_NAME_LEN, stdin);
  query[strcspn(query, "\n")] = '\0';

  int is_numeric_input = sscanf(query, "%lf %lf %lf", &x, &y, &distance);

  printf("\n--- Search Results ---\n");
  int found = 0;

  if (is_numeric_input == 3) {
    // 숫자 3개 입력 처리 (x, y, 거리 d)
    for (int i = 0; i < manager->count; i++) {
      if (calculate_distance(x, y, manager->restaurants[i].x, manager->restaurants[i].y) <= distance) {
        print_restaurant(manager->restaurants[i]);
        found = 1;
      }
    }
  } else if (get_food_type(query) != Unknown) {
    // 음식 종류 입력 처리
    FoodType type = get_food_type(query);
    for (int i = 0; i < manager->count; i++) {
      if (manager->restaurants[i].type == type) {
        print_restaurant(manager->restaurants[i]);
        found = 1;
      }
    }
  } else {
    // 부분 문자열 검색 처리
    for (int i = 0; i < manager->count; i++) {
      if (strstr(manager->restaurants[i].name, query) != NULL) {
        print_restaurant(manager->restaurants[i]);
        found = 1;
      }
    }
  }

  if (!found) {
    printf("No result\n");
  }
}

// 동적 배열의 크기를 재할당하는 함수
void reallocate_restaurants(RestaurantManager *manager) {
  manager->capacity *= 2;
  manager->restaurants = (Restaurant *)realloc(manager->restaurants,
                                               sizeof(Restaurant) * manager->capacity);

  if (manager->restaurants == NULL) {
    printf("Memory reallocation error!\n");
    exit(1);
  }
}

// 두 점 사이의 거리를 계산하는 함수
double calculate_distance(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// 음식 종류를 문자열로 변환하는 함수
FoodType get_food_type(const char *type_str) {
  if (strcmp(type_str, "Korean") == 0) {
    return Korean;
  } else if (strcmp(type_str, "Chinese") == 0) {
    return Chinese;
  } else if (strcmp(type_str, "Japanese") == 0) {
    return Japanese;
  } else if (strcmp(type_str, "Western") == 0) {
    return Western;
  } else {
    return Unknown;
  }
}

// 음식 종류를 출력하는 함수
void print_food_type(FoodType type) {
  switch (type) {
  case Korean:
    printf("Korean");
    break;
  case Chinese:
    printf("Chinese");
    break;
  case Japanese:
    printf("Japanese");
    break;
  case Western:
    printf("Western");
    break;
  default:
    printf("Unknown");
  }
}

// 식당 정보를 출력하는 함수
void print_restaurant(Restaurant restaurant) {
  printf("Name: %s, Type: ", restaurant.name);
  print_food_type(restaurant.type);
  printf(", Location: (%.2lf, %.2lf), Score: %.1lf\n", 
         restaurant.x, restaurant.y, restaurant.score);
}

// 메인 함수
int main() {
  RestaurantManager manager;
  manager.capacity = INIT_CAPACITY;
  manager.count = 0;

  manager.restaurants = (Restaurant *)malloc(sizeof(Restaurant) * manager.capacity);

  if (manager.restaurants == NULL) {
    printf("Memory allocation error!\n");
    exit(1);
  }

  int choice;
  while (1) {
    printf("\n--- Restaurant Management ---\n");
    printf("1. Add restaurant information\n");
    printf("2. Recommend restaurants\n");
    printf("3. Search for restaurants\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid choice.\n");
      fflush(stdin);
      continue;
    }

    getchar();

    switch (choice) {
    case 1:
      add_restaurant(&manager);
      break;
    case 2:
      recommend_restaurants(&manager);
      break;
    case 3:
      search_restaurants(&manager);
      break;
    case 4:
      printf("Exiting program. Memory cleared.\n");
      free(manager.restaurants);
      return 0;
    default:
      printf("Invalid choice.\n");
    }
  }

  return 0;
}

