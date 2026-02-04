generate a time signature (4/4 for now)
generate a root key (0-11)
generate a scale based on root key (0, 2, 4, 5, 7, 9, 11)
generate an octave (melodic tonic between like E3-G5)

generate motif(s)

# Chords
(assumes major scale for now for my sanity, if I wanted to implement other modes I'd get rabit-holed)

I:
- can go to anything, IV/vi most likely
- V is possible for I-V-I
ii:
- Most likely to go to V
iii:
- Most likely to go to vi, not likely to be played
IV:
- vi is likely IF (n-1)th chord was not vi
- V is likely
- vii is possible but rare
- I is likely
V:
- Will usually resolve to I.
- Could go to vi. Shouldn't really do anything else.
vi:
- Can go to IV *if* (n-1)th chord was not IV
- Can go to V
- may go to I
- May go to ii
vii:
- may go to iii
- may go to I


Dynamic weights considering:
Previous chord(s)
Chords since tonic


# Melody:
Should be in alignment with chords (you wouldn't play a tonic over a V[for the sake of reasonably sounding, albeit uninteresting, music])

- Should focus on movement along the scale
- Should be most likely to move to the next note up or down
- Duration should be varied, and weighted to be longer on a jump
