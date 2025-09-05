#3.1
names = ['A', 'B', 'C', 'D', 'E']
for name in names:
    print(name)
#3.2
names = ['A', 'B', 'C', 'D', 'E']
for name in names:
    print(f"Hello {name}")

#3.3
transport = ['Honda', 'Yamaha', 'Suzuki']
for vehicle in transport:
    print(f"Transport: {vehicle}")

#3.4
names = ['A', 'B', 'C']
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")

#3.5
names = ['A', 'B', 'C']
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")
print('A')
names[0] = 'D'
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")

#3.6
names = ['A', 'B', 'C']
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")
print('A')
names[0] = 'D'
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")
print('Toi tim duoc ban an lon hon')
names.insert(0, 'F')
names.insert(2, 'G')
names.append('H')
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")

#3.7
names = ['A', 'B', 'C']
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")
print('A')
names[0] = 'D'
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")
print('Toi tim duoc ban an lon hon')
names.insert(0, 'F')
names.insert(2, 'G')
names.append('H')
for name in names:
    print(f"Ban di an toi voi minh nhe, {name}")
print('Toi chi co 2 ban di an toi voi minh')
while len(names) > 2:
    removed_name = names.pop()
    print(f"Xin loi {removed_name}")
for name in names:
    print(f"Ban van di voi minh nhe, {name}")
del names[0]
del names[1]
print(names)


#3.8
worlds = ['A', 'C', 'B', 'H', 'D']
print(*worlds)
print(sorted(worlds))
print(*worlds)
worlds.reverse()
print(*worlds)
worlds.reverse()
worlds.sort()
print(*worlds)
worlds.sort(reverse=True)
print(*worlds)

#3.9
worlds = ['A', 'C', 'B', 'H', 'D']
print(len(worlds))

#3.10
worlds = ['A', 'C', 'B', 'H', 'D']
print(len(worlds))
print(sorted(worlds))
print(*worlds)
worlds.reverse()
print(*worlds)
worlds.reverse()
worlds.sort()
print(*worlds)
worlds.sort(reverse=True)
print(*worlds)