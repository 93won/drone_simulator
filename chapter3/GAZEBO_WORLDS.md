# Gazebo World (환경 맵) 사용 가이드

## 사용 가능한 월드 목록

### 실내 환경
- **warehouse.world** - 창고 환경 (SLAM 테스트에 최적!) 🏭
- **safe_landing.world** - 안전 착륙 테스트용 환경

### 실외 환경
- **baylands.world** - 베이랜즈 지형
- **ksql_airport.world** - 공항 환경 ✈️
- **mcmillan_airfield.world** - 비행장
- **sonoma_raceway.world** - 레이스트랙 🏁
- **yosemite.world** - 요세미티 국립공원

### 특수 환경
- **empty.world** - 빈 환경 (기본값)
- **windy.world** - 바람 시뮬레이션 💨
- **ramped_up_wind.world** - 강한 바람
- **ocean.world** - 해양 환경 🌊

### 차량별 특수 월드
- **typhoon_h480.world** - 헥사콥터용
- **iris_irlock.world** - IR 마커 추적용
- **boat.world** - 보트 시뮬레이션
- **uuv_hippocampus.world** - 수중 드론

## 월드 사용 방법

### ⭐ 올바른 문법 (권장!)

PX4에서 특정 world를 지정하는 **올바른 방법**:

```bash
cd ~/drone_simulator/PX4-Autopilot

# 문법: make px4_sitl gazebo-classic_모델명__world명
# 중요: 언더스코어 2개 (__) 사용!

# Warehouse 환경
make px4_sitl gazebo-classic_iris_depth_camera__warehouse

# Yosemite 환경
make px4_sitl gazebo-classic_iris_depth_camera__yosemite

# Baylands 환경
make px4_sitl gazebo-classic_iris_depth_camera__baylands
```

### 대체 방법: 환경변수 사용

```bash
cd ~/drone_simulator/PX4-Autopilot

# PX4_SITL_WORLD 환경변수 설정
export PX4_SITL_WORLD=warehouse
make px4_sitl gazebo-classic_iris_depth_camera
```

**주의**: 환경변수 방법은 때때로 작동하지 않을 수 있습니다. `__world명` 문법을 권장합니다!

## 편리한 실행 스크립트

각 월드별로 빠른 실행 스크립트를 만들 수 있습니다:

### warehouse_sim.sh
```bash
#!/bin/bash
cd ~/drone_simulator/PX4-Autopilot
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
```

### yosemite_sim.sh
```bash
#!/bin/bash
cd ~/drone_simulator/PX4-Autopilot
make px4_sitl gazebo-classic_iris_depth_camera__yosemite
```

**스크립트를 실행 가능하게 만들기:**
```bash
chmod +x warehouse_sim.sh yosemite_sim.sh
```

### 제공된 스크립트 사용하기

`chapter3` 폴더에 이미 warehouse 스크립트가 있습니다:

```bash
cd ~/drone_simulator/chapter3
./run_depth_warehouse.sh
```

## 월드 특징

### 🏭 Warehouse (강력 추천!)
- **용도**: SLAM, 실내 내비게이션, obstacle avoidance
- **특징**: 
  - 벽과 기둥이 있는 실내 구조
  - Depth camera로 맵핑하기 좋음
  - 복잡한 장애물 환경
- **파일 크기**: 12.8 KB (복잡한 구조)

### ✈️ KSQL Airport
- **용도**: 실외 비행, GPS 기반 내비게이션
- **특징**: 활주로, 건물, 넓은 공간

### 🌲 Yosemite
- **용도**: 자연 환경 비행
- **특징**: 산악 지형

### 💨 Windy
- **용도**: 바람 영향 테스트, 안정성 테스트
- **특징**: 바람 시뮬레이션 (드론 제어 난이도 증가)

### 🏁 Sonoma Raceway
- **용도**: 경로 추적, 고속 비행
- **특징**: 레이스트랙, 타이밍 게이트

### 🌊 Ocean
- **용도**: 해상 작전 시뮬레이션
- **특징**: 물 표면, 파도 효과

## SLAM 테스트용 추천 월드

### 1순위: Warehouse 🏆
```bash
make px4_sitl gazebo-classic_iris_depth_camera__warehouse
```
- 실내 SLAM에 최적
- 명확한 특징점 (벽, 기둥)
- 복잡도 적절

### 2순위: Safe Landing
```bash
make px4_sitl gazebo-classic_iris_depth_camera__safe_landing
```
- 다양한 장애물
- 착륙 테스트 가능

## 월드 내용 확인

월드 파일을 직접 확인하려면:
```bash
# Warehouse 월드 내용 보기
cat PX4-Autopilot/Tools/simulation/gazebo-classic/sitl_gazebo-classic/worlds/warehouse.world

# 모든 월드 파일 리스트
ls -lh PX4-Autopilot/Tools/simulation/gazebo-classic/sitl_gazebo-classic/worlds/
```

## 커스텀 월드 생성

자신만의 월드를 만들고 싶다면:
```bash
# 기존 월드 복사
cp ~/drone_simulator/PX4-Autopilot/Tools/simulation/gazebo-classic/sitl_gazebo-classic/worlds/warehouse.world \
   ~/drone_simulator/PX4-Autopilot/Tools/simulation/gazebo-classic/sitl_gazebo-classic/worlds/my_world.world

# 편집
nano ~/drone_simulator/PX4-Autopilot/Tools/simulation/gazebo-classic/sitl_gazebo-classic/worlds/my_world.world

# 실행
make px4_sitl gazebo-classic_iris_depth_camera__my_world
```

## 빠른 테스트

각 월드를 빠르게 테스트하려면:
```bash
cd ~/drone_simulator/PX4-Autopilot

# 1. Warehouse
make px4_sitl gazebo-classic_iris_depth_camera__warehouse

# Gazebo 창에서 드론 위치 확인
# Ctrl+C로 종료

# 2. Yosemite
make px4_sitl gazebo-classic_iris_depth_camera__yosemite
```

## 빠른 명령어 참조

```bash
# Empty (기본)
make px4_sitl gazebo-classic_iris_depth_camera

# Warehouse (창고) - SLAM 최적! 🏆
make px4_sitl gazebo-classic_iris_depth_camera__warehouse

# Baylands (야외 지형)
make px4_sitl gazebo-classic_iris_depth_camera__baylands

# KSQL Airport (공항)
make px4_sitl gazebo-classic_iris_depth_camera__ksql_airport

# McMillan Airfield (비행장)
make px4_sitl gazebo-classic_iris_depth_camera__mcmillan_airfield

# Sonoma Raceway (경주로)
make px4_sitl gazebo-classic_iris_depth_camera__sonoma_raceway

# Yosemite (산악 지형)
make px4_sitl gazebo-classic_iris_depth_camera__yosemite

# Windy (바람 환경)
make px4_sitl gazebo-classic_iris_depth_camera__windy

# Safe Landing
make px4_sitl gazebo-classic_iris_depth_camera__safe_landing
```

## 다음 단계

Warehouse 환경에서:
1. Depth camera로 3D 스캔
2. SLAM으로 맵 생성
3. Obstacle avoidance 테스트
4. 자율 내비게이션 구현
