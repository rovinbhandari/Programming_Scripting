namespace Lists

// https://wiki.haskell.org/99_questions/11_to_20
module _11to20 =
    type ToV<'T> =
        | V of 'T
        | T of (int, V)
    let EncodeModified (list: List<ToV<'T>>) = list