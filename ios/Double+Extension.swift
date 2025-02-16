//
//  Double+Extension.swift
//  NitroEventKit
//
//  Created by VLAD on 15.02.2025.
//

import Foundation


extension Double {
    var asDateFromMilliseconds: Date {
        Date(timeIntervalSince1970: self / 1000)
    }
}
