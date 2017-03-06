namespace Lists

// https://wiki.haskell.org/99_questions/1_to_10
module _1to10 =
    let Last = List.last
    
    let Penultimate l = List.rev l |> List.skip 1 |> List.head
    
    let Kth k l = l |> List.skip (k - 1) |> List.head
    
    let Length = List.length
    
    let Reverse = List.rev
    
    let Palindrome l = l = Reverse l

    // define list of lists since lists are homogenous in F#
    type LoL<'T> =
        | V of 'T
        | L of LoL<'T> list
    let rec Flatten (lol: LoL<'T>) =
        match lol with
        | V v -> [v]
        | L l -> List.fold (fun acc a -> acc@(Flatten a)) [] l

    let Compress (l: List<'T>) = 
        List.fold (fun acc a -> acc@(if a = (List.last acc) then [] else [a])) [l.Head] l

    let Repeat i n = // List of i repeated n times
        Seq.replicate n i |> Seq.toList
    let COAH a b =  // Consecutive Occurrences At Head of a in b
        match b with
        | [] -> 0
        | [x] -> if x = a then 1 else 0
        | h::t -> (List.takeWhile (fun i -> i = h) t |> List.length) + 1
    let Sublist b j = // Sublist of b starting at index j until the end
        b |> List.skip j
    let rec private _Pack (accumulator: List<List<'T>>) (list: List<'T>) =
        match list with
        | [] -> accumulator
        | h::t as l -> accumulator@[Repeat h (COAH h l)]@(_Pack [] (Sublist l (COAH h l)))
    let Pack (l: List<'T>) = _Pack [] l

    let Encode (l: List<'T>) =
        l |> Pack |> List.map (fun e -> (e.Length, e.Head))