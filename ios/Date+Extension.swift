//
//  Date+Extension.swift
//  NitroEventKit
//
//  Created by VLAD on 15.02.2025.
//

import Foundation

extension Date {
    var unixTimestampInMilliseconds: Double {
        self.timeIntervalSince1970 * 1000
    }
}
