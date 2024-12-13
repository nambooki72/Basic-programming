#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 20      // 주민등록번호 문자열 최대 길이
#define MAX_RECORDS 100 // 저장 가능한 최대 주민등록번호 개수
#define KEY_LEN 10     // 암호화 키 길이

// 주민등록번호 구조체 정의
typedef struct {
    char ssn[MAX_LEN];    // 주민등록번호 (XXXXXX-XXXXXXX 형식)
    int is_encrypted;     // 암호화 상태 (0: 평문, 1: 암호화)
} SSNRecord;

// 전체 레코드 관리 구조체
typedef struct {
    SSNRecord records[MAX_RECORDS]; 
    int count;            // 저장된 주민등록번호 개수
} SSNManager;

// 암호화 키 생성 함수 (주민등록번호 앞 12자리와 가중치를 곱한 합을 11로 나눈 나머지 사용)
void generate_encryption_key(const char* ssn, char* key) {
    int sum = 0;
    int weights[] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5}; // 가중치 배열
    
    for (int i = 0; i < 12; i++) {
        if (ssn[i] != '-') {
            sum += (ssn[i] - '0') * weights[i];
        }
    }

    sum %= 11; // 11로 나눈 나머지

    // a부터 j까지의 알파벳으로 키 생성
    for (int i = 0; i < KEY_LEN; i++) {
        key[i] = 'a' + ((sum + i) % 10); 
    }
    key[KEY_LEN] = '\0'; 
}

// 암호화 함수 (각 자리에 키값을 더한 후 알파벳으로 변환)
void encrypt_ssn(char* ssn, const char* key) {
    int key_idx = 0;
    int key_len = strlen(key);

    for (int i = 0; ssn[i] != '\0'; i++) {
        if (ssn[i] >= '0' && ssn[i] <= '9') {
            int num = ssn[i] - '0';
            int key_val = key[key_idx % key_len] - 'a';
            ssn[i] = 'a' + ((num + key_val) % 10); 
            key_idx++;
        }
        // 하이픈은 그대로 유지
    }
}

// 복호화 함수 (암호화의 역과정 수행)
void decrypt_ssn(char* encrypted_ssn, const char* key) {
    int key_idx = 0;
    int key_len = strlen(key);

    for (int i = 0; encrypted_ssn[i] != '\0'; i++) {
        if (encrypted_ssn[i] >= 'a' && encrypted_ssn[i] <= 'j') {
            int val = encrypted_ssn[i] - 'a';
            int key_val = key[key_idx % key_len] - 'a';
            int num = (val - key_val + 10) % 10; // 음수 방지를 위해 +10
            encrypted_ssn[i] = '0' + num;
            key_idx++;
        }
    }
}

// 주민등록번호 생성 함수 (생년월일, 성별 입력 받아 생성)
void generate_ssn(SSNRecord* record) {
    char birth[9];
    int gender;

    printf("생년월일 입력 (예: 19990101): ");
    scanf("%s", birth);

    // 생년월일 유효성 검사 (간단한 검사만 추가)
    if (strlen(birth) != 8) {
        printf("잘못된 생년월일 형식입니다.\n");
        return;
    }

    printf("성별 입력 (남: 1, 여: 2): ");
    scanf("%d", &gender);

    // 성별 유효성 검사
    if (gender != 1 && gender != 2) {
        printf("잘못된 성별입니다.\n");
        return;
    }

    // 2000년대생 성별 코드 변환
    int year = (birth[0] - '0') * 1000 + (birth[1] - '0') * 100;
    if (year >= 2000) {
        gender += 2; 
    }

    // 랜덤 숫자 생성 및 주민등록번호 생성
    int random_nums[6];
    for (int i = 0; i < 6; i++) {
        random_nums[i] = rand() % 10;
    }

    sprintf(record->ssn, "%c%c%c%c%c%c-%d%d%d%d%d%d", 
            birth[2], birth[3], birth[4], birth[5], birth[6], birth[7], 
            gender, random_nums[0], random_nums[1], random_nums[2], 
            random_nums[3], random_nums[4]);

    // 마지막 자리 숫자 계산 (generate_encryption_key 함수 활용)
    char temp_key[KEY_LEN + 1];
    generate_encryption_key(record->ssn, temp_key); 
    int last_digit = temp_key[0] - 'a'; // 키의 첫 번째 문자를 숫자로 변환
    record->ssn[14] = last_digit + '0'; // 마지막 자리에 숫자 추가

    record->is_encrypted = 0;
    printf("생성된 주민등록번호: %s\n", record->ssn);
}


int main() {
    SSNManager manager = {0};  // 구조체 초기화
    char key[KEY_LEN + 1];     // 암호화 키
    int choice;
    int key_generated = 0; // 암호화 키 생성 여부를 저장하는 변수 추가

    srand(time(NULL)); // 랜덤 시드 초기화

    while (1) {
        printf("===== 주민등록번호 관리 프로그램 =====\n");
        printf("1. 주민등록번호 생성\n");
        printf("2. 주민등록번호 조회\n");
        printf("3. 주민등록번호 암호화\n");
        printf("4. 주민등록번호 복호화\n");
        printf("5. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { 
                if (manager.count < MAX_RECORDS) {
                    generate_ssn(&manager.records[manager.count]);
                    manager.count++;
                } else {
                    printf("더 이상 주민등록번호를 저장할 수 없습니다.\n");
                }
                break;
            }
            case 2: 
                if (manager.count == 0) {
                    printf("저장된 주민등록번호가 없습니다.\n");
                } else {
                    for (int i = 0; i < manager.count; i++) {
                        printf("번호 %d: ", i + 1);
                        if (manager.records[i].is_encrypted) {
                            printf("암호화된 주민등록번호: %s\n", manager.records[i].ssn);
                        } else {
                            printf("평문 주민등록번호: %s\n", manager.records[i].ssn);
                        }
                    }
                }
                break;
            case 3: { 
                if (manager.count == 0) {
                    printf("저장된 주민등록번호가 없습니다.\n");
                } else {
                    if (!key_generated) { // 암호화 키가 생성되지 않은 경우에만 키 생성 및 출력
                        generate_encryption_key(manager.records[0].ssn, key); // 키 생성
                        printf("생성된 암호화 키: %s\n", key); // 키 출력
                        key_generated = 1; // 키 생성 여부 업데이트
                    }

                    for (int i = 0; i < manager.count; i++) {
                        if (manager.records[i].is_encrypted) {
                            printf("이미 암호화된 주민등록번호입니다. \n"); // 이미 암호화된 경우 메시지 출력
                        } else {
                            encrypt_ssn(manager.records[i].ssn, key);
                            manager.records[i].is_encrypted = 1;
                            printf("암호화된 주민등록번호: %s\n", manager.records[i].ssn);
                        }
                    }
                }
                break;
            }
            case 4: { 
                if (manager.count == 0) {
                    printf("저장된 주민등록번호가 없습니다.\n");
                } else {
                    printf("복호화할 주민등록번호의 번호를 입력하세요: ");
                    int index;
                    scanf("%d", &index);

                    if (index > 0 && index <= manager.count) {
                        if (manager.records[index - 1].is_encrypted) {
                            decrypt_ssn(manager.records[index - 1].ssn, key);
                            manager.records[index - 1].is_encrypted = 0;
                            printf("복호화된 주민등록번호: %s\n", manager.records[index - 1].ssn);
                        } else {
                            printf("암호화되지 않은 주민등록번호입니다.\n");
                        }
                    } else {
                        printf("잘못된 번호입니다.\n");
                    }
                }
                break;
            }
            case 5: 
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다.\n");
        }
        printf("\n");
    }
    return 0;
}
