import random
import numpy as np

MAP_WIDTH = 64
MAP_HEIGHT = 64

WALL = 1
EMPTY = 0
JOJO = 2
CHEUVEUX = 3
HOPPY_WHERE = 4
HOPPY_CAT = 5

map_data = np.full((MAP_HEIGHT, MAP_WIDTH), WALL, dtype=int)
rooms = []

def carve_room(x, y, w, h, tile=EMPTY):
    for i in range(y, y + h):
        for j in range(x, x + w):
            if 0 <= i < MAP_HEIGHT and 0 <= j < MAP_WIDTH:
                map_data[i][j] = tile

def place_special_walls(x, y, w, h, tile):
    perimeter = []
    for i in range(w):
        perimeter.append((y, x + i))
        perimeter.append((y + h - 1, x + i))
    for i in range(1, h - 1):
        perimeter.append((y + i, x))
        perimeter.append((y + i, x + w - 1))
    random.shuffle(perimeter)
    for (py, px) in perimeter[:3]:
        map_data[py][px] = tile

def add_room(x, y, w, h, special_tile=None):
    carve_room(x, y, w, h)
    if special_tile:
        place_special_walls(x, y, w, h, special_tile)
    rooms.append(((x, y), (x + w - 1, y + h - 1)))

def carve_corridor(start, end):
    x1, y1 = start
    x2, y2 = end
    if random.choice([True, False]):
        for x in range(min(x1, x2), max(x1, x2) + 1):
            map_data[y1][x] = EMPTY
        for y in range(min(y1, y2), max(y1, y2) + 1):
            map_data[y][x2] = EMPTY
    else:
        for y in range(min(y1, y2), max(y1, y2) + 1):
            map_data[y][x1] = EMPTY
        for x in range(min(x1, x2), max(x1, x2) + 1):
            map_data[y2][x] = EMPTY

def find_empty_tile():
    while True:
        x = random.randint(1, MAP_WIDTH - 2)
        y = random.randint(1, MAP_HEIGHT - 2)
        if map_data[y][x] == EMPTY:
            return x + 0.5, y + 0.5

def generate_map_with_entities():
    global map_data, rooms
    map_data = np.full((MAP_HEIGHT, MAP_WIDTH), WALL, dtype=int)
    rooms = []

    add_room(2, 2, 10, 10)

    for _ in range(15):
        x = random.randint(2, MAP_WIDTH - 12)
        y = random.randint(2, MAP_HEIGHT - 12)
        w = random.randint(6, 10)
        h = random.randint(6, 10)
        special = random.choice([JOJO, CHEUVEUX, HOPPY_WHERE, HOPPY_CAT, None])
        add_room(x, y, w, h, special)

    add_room(MAP_WIDTH - 12, MAP_HEIGHT - 12, 10, 10, HOPPY_WHERE)

    for i in range(1, len(rooms)):
        x1 = (rooms[i - 1][0][0] + rooms[i - 1][1][0]) // 2
        y1 = (rooms[i - 1][0][1] + rooms[i - 1][1][1]) // 2
        x2 = (rooms[i][0][0] + rooms[i][1][0]) // 2
        y2 = (rooms[i][0][1] + rooms[i][1][1]) // 2
        carve_corridor((x1, y1), (x2, y2))

    lines = [f"MAP_SIZE {MAP_WIDTH} {MAP_HEIGHT}"]
    lines += [" ".join(str(cell) for cell in row) for row in map_data]

    lines.append("")
    lines.append("[ENTITIES]")

    px, py = find_empty_tile()
    lines.append(f"player {px} {py} 90")

    cx, cy = find_empty_tile()
    lines.append(f"computer {cx} {cy} 180")

    for _ in range(random.randint(3, 10)):
        jx, jy = find_empty_tile()
        lines.append(f"jojo {jx} {jy} 180")

    for _ in range(random.randint(1, 3)):
        hx, hy = find_empty_tile()
        lines.append(f"hoppy {hx} {hy} 180")

    with open("worlds/test.world", "w") as f:
        f.write("\n".join(lines))

    print("Map et entités générées dans 'generated_map_with_entities.txt'.")

if __name__ == "__main__":
    generate_map_with_entities()
